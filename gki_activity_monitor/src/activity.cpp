/*
 * activity.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/activity.h>

namespace activity_monitoring
{

Activity::Ptr Activity::start(const std::string& description, bool wall_time_only)
{
  gki_activity_msgs::Activity::Ptr msg(new gki_activity_msgs::Activity);
  msg->description = description;
  ros::WallTime t = ros::WallTime::now();
  msg->start_wall_time.sec = t.sec;
  msg->start_wall_time.nsec = t.nsec;
  if (! wall_time_only)
  {
    msg->start_time = ros::Time::now();
  }
  msg->id = Activity::id_generator(rng);
  Activity::Ptr a(new Activity(msg));
  return a;
}

Activity::Ptr Activity::fromMsg(gki_activity_msgs::Activity::ConstPtr msg)
{
  Activity::Ptr a(new Activity(msg));
  return a;
}

Activity::Activity(gki_activity_msgs::Activity::ConstPtr msg):
    msg_(msg)
{
  start_wall_time_.sec = msg_->start_wall_time.sec;
  start_wall_time_.nsec = msg_->start_wall_time.nsec;
  finish_wall_time_.sec = msg_->finish_wall_time.sec;
  finish_wall_time_.nsec = msg_->finish_wall_time.nsec;
  is_finished_ = finish_wall_time_ > ros::WallTime(0);
  if (is_finished_)
  {
    wall_duration_ = finish_wall_time_ - start_wall_time_;
    duration_ = msg_->finish_time - msg_->start_time;
  }
}

Activity::~Activity()
{
}

void Activity::finish()
{
  gki_activity_msgs::Activity::Ptr msg(new gki_activity_msgs::Activity);
  *msg = *msg_;
  ros::WallTime t = ros::WallTime::now();
  msg->finish_wall_time.sec = t.sec;
  msg->finish_wall_time.nsec = t.nsec;
  if (! usesWallTimeOnly())
  {
    msg->finish_time = ros::Time::now();
  }
  msg_ = msg;
}

const ros::WallTime& Activity::getStartWallTime() const
{
  return start_wall_time_;
}

const ros::WallTime& Activity::getFinishWallTime() const
{
  return finish_wall_time_;
}

const ros::Time& Activity::getStartTime() const
{
  return msg_->start_time;
}

const ros::Time& Activity::getFinishTime() const
{
  return msg_->finish_time;
}

const ros::WallDuration& Activity::getWallDuration() const
{
  return wall_duration_;
}

const ros::Duration& Activity::getDuration() const
{
  return duration_;
}

bool Activity::isFinished() const
{
  return is_finished_;
}

bool Activity::usesWallTimeOnly() const
{
  return msg_->start_time <= ros::Time(0);
}

gki_activity_msgs::Activity::_id_type Activity::getId() const
{
  return msg_->id;
}

gki_activity_msgs::Activity::ConstPtr Activity::getMsg() const
{
  return msg_;
}

} /* namespace activity_monitoring */
