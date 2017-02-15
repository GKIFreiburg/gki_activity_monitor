/*
 * activity_timeline.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/timeline.h>

namespace activity_monitoring
{

Event Event::start(Activity::ConstPtr a)
{
  Event e;
  e.activity_id = a->getId();
  e.event_time = a->getStartWallTime();
  e.type = Event::ACTIVITY_START;
  return e;
}

Event Event::finish(Activity::ConstPtr a)
{
  Event e;
  e.activity_id = a->getId();
  e.event_time = a->getFinishWallTime();
  e.type = Event::ACTIVITY_FINISH;
  return e;
}

Timeline::Timeline()
{
}

Timeline::~Timeline()
{
}

void Timeline::insert(const Activity::ConstPtr a)
{
  events_[Event::start(a)] = a;
  if (a->isFinished())
  {
    events_[Event::finish(a)] = a;
  }
}

void Timeline::clear()
{
  events_.clear();
}

EventTimelineMap::const_iterator Timeline::begin() const
{
  return events_.begin();
}

EventTimelineMap::const_iterator Timeline::end() const
{
  return events_.end();
}

} /* namespace activity_monitoring */
