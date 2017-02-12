/*
 * activity.h
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#ifndef SRC_ACTIVITY_H_
#define SRC_ACTIVITY_H_

#include <boost/shared_ptr.hpp>
#include <gki_activity_msgs/Activity.h>
#include <boost/random.hpp>

namespace activity_monitoring
{

class Activity
{
public:
  typedef boost::shared_ptr<Activity> Ptr;
  typedef boost::shared_ptr<Activity const> ConstPtr;

  static Activity::Ptr start(const std::string& description, bool wall_time_only = false);
  static Activity::Ptr fromMsg(gki_activity_msgs::Activity::ConstPtr msg);
  virtual ~Activity();

  void finish();

  const ros::WallTime& getStartWallTime() const;
  const ros::WallTime& getFinishWallTime() const;
  const ros::WallDuration& getWallDuration() const;

  const ros::Time& getStartTime() const;
  const ros::Time& getFinishTime() const;
  const ros::Duration& getDuration() const;

  bool isFinished() const;
  bool usesWallTimeOnly() const;
  gki_activity_msgs::Activity::_id_type getId() const;
  const std::string& getDescription() const;

  gki_activity_msgs::Activity::ConstPtr getMsg() const;

private:
  Activity(gki_activity_msgs::Activity::ConstPtr msg);
  gki_activity_msgs::Activity::ConstPtr msg_;
  ros::WallTime start_wall_time_;
  ros::WallTime finish_wall_time_;
  ros::WallDuration wall_duration_;
  ros::Duration duration_;
  bool is_finished_;

  static boost::random::mt19937 rng;
  static boost::random::uniform_int_distribution<gki_activity_msgs::Activity::_id_type> id_generator;
};

} /* namespace activity_monitoring */

#endif /* SRC_ACTIVITY_H_ */
