/*
 * scoped_activity.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/scoped_activity.h>

namespace activity_monitoring
{

ScopedActivity::ScopedActivity(const std::string& description, bool use_wall_time)
{
  activity_ = Activity::start(description, use_wall_time);
  monitor_ = Monitor::instance();
  monitor_->addAction(activity_->msg_);
}

ScopedActivity::~ScopedActivity()
{
  activity_->finish();
  monitor_->addAction(activity_->msg_);
}

} /* namespace activity_monitoring */
