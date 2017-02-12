/*
 * activity_timeline.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/timeline.h>

namespace activity_monitoring
{

Timeline::Timeline()
{
}

Timeline::~Timeline()
{
}

void Timeline::insert(const Activity::ConstPtr a)
{
  started_.insert(a);
  if (a->isFinished())
  {
    finished_.insert(a);
  }
}

size_t Timeline::erase(Activity::ConstPtr a)
{
  finished_.erase(a);
  return finished_.erase(a);
}

void Timeline::clear()
{
  started_.clear();
  finished_.clear();
}

const Timeline::StartedActivitySet& Timeline::getStartedActivities() const
{
  return started_;
}

const Timeline::FinishedActivitySet& Timeline::getFinishedActivities() const
{
  return finished_;
}

//EventIterator Timeline::begin() const
//{
//
//}
//
//EventIterator Timeline::end() const
//{
//
//}

} /* namespace activity_monitoring */
