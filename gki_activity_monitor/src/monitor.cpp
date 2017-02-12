/*
 * activity_monitor_server.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/monitor.h>

#include <boost/make_shared.hpp>

namespace activity_monitoring
{

boost::weak_ptr<Monitor> Monitor::instance_;

Monitor::Ptr Monitor::instance()
{
  Ptr temp = instance_.lock();
  if (temp == NULL)
  {
    temp.reset(new Monitor);
  }
  return temp;
}

Monitor::Monitor()
{
  ros::NodeHandle n;
  subscriber_ = n.subscribe("activities", 10, &Monitor::activityCallback, this);
  publisher_ = n.advertise<gki_activity_msgs::Activity>("activities", 10, false);
}

Monitor::~Monitor()
{
}

void Monitor::activityCallback(gki_activity_msgs::Activity::ConstPtr msg)
{
  Activity::Ptr activity = Activity::fromMsg(msg);
  activities_.insert(activity);
}

void Monitor::addActivity(gki_activity_msgs::Activity::ConstPtr msg)
{
  // publish to peers and to self
  publisher_.publish(msg);
}

} /* namespace activity_monitoring */
