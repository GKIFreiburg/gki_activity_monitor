/*
 * activity_monitor_server.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/monitor.h>

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
  activities_.reset(new Timeline);
  ros::NodeHandle n;
  subscriber_ = n.subscribe("activities", 100, &Monitor::activityCallback, this);
  publisher_ = n.advertise<gki_activity_msgs::Activity>("activities", 100, false);
}

Monitor::~Monitor()
{
}

void Monitor::activityCallback(gki_activity_msgs::Activity::ConstPtr msg)
{
  Activity::Ptr activity = Activity::fromMsg(msg);
  activities_->insert(activity);
}

void Monitor::addActivity(gki_activity_msgs::Activity::ConstPtr msg)
{
  // publish to peers and to self
  publisher_.publish(msg);
}

Timeline::ConstPtr Monitor::getTimeline() const
{
  return activities_;
}

} /* namespace activity_monitoring */
