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
#include <gki_activity_msgs/Activity.h>

#include <gki_activity_monitor/activity.h>
#include <gki_activity_monitor/timeline.h>

namespace activity_monitoring
{

class Monitor
{
public:
  typedef boost::shared_ptr<Monitor> Ptr;

  static Monitor::Ptr instance();
  virtual ~Monitor();

  void activityCallback(gki_activity_msgs::Activity::ConstPtr msg);
  void addActivity(gki_activity_msgs::Activity::ConstPtr msg);

  Timeline::ConstPtr getTimeline() const;

private:
  Monitor();
  static boost::weak_ptr<Monitor> instance_;

  Timeline::Ptr activities_;

  ros::Subscriber subscriber_;
  ros::Publisher publisher_;
};

} /* namespace activity_monitoring */

#endif /* SRC_MONITOR_H_ */
