/*
 * monitor.h
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#ifndef SRC_MONITOR_H_
#define SRC_MONITOR_H_

#include <ros/ros.h>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <gki_activity_msgs/Activity.h>
#include <gki_activity_monitor/activity.h>

namespace activity_monitoring
{

class Monitor
{
public:
  typedef boost::shared_ptr<Monitor> Ptr;
  typedef std::map<gki_activity_msgs::Activity::_id_type, Activity::Ptr> ActivityContainer;

  static Monitor::Ptr instance();
  virtual ~Monitor();

  void activityCallback(gki_activity_msgs::Activity::ConstPtr msg);
  void addAction(gki_activity_msgs::Activity::ConstPtr msg);

private:
  Monitor();
  static boost::weak_ptr<Monitor> instance_;

  ActivityContainer ongoing_;
  ActivityContainer finished_;

  ros::Subscriber subscriber_;
  ros::Publisher publisher_;
};

} /* namespace activity_monitoring */

#endif /* SRC_MONITOR_H_ */
