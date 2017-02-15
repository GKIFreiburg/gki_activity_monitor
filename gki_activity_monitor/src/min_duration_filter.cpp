/*
 * min_duration_filter.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/min_duration_filter.h>

namespace activity_monitoring
{

MinDurationFilter::MinDurationFilter(const ros::WallDuration& duration):
    duration_(duration)
{
}

MinDurationFilter::~MinDurationFilter()
{
}

bool MinDurationFilter::exclude(Activity::ConstPtr a) const
{
  return a->getWallDuration() >= duration_;
}

} /* namespace activity_monitoring */
