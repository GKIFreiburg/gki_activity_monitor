/*
 * scoped_activity.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/scoped_activity.h>

namespace activity_monitoring
{

ScopedActivity::ScopedActivity(const std::string& description, bool wall_time_only)
{
  activity_ = Activity::start(description, wall_time_only);
  monitor_ = Monitor::instance();
  monitor_->addActivity(activity_->getMsg());
}

ScopedActivity::~ScopedActivity()
{
  activity_->finish();
  monitor_->addActivity(activity_->getMsg());
}

} /* namespace activity_monitoring */
