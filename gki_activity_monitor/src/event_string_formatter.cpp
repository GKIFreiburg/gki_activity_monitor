/*
 * event_string_formatter.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: andreas
 */

#include <gki_activity_monitor/event_string_formatter.h>

namespace activity_monitoring
{

EventStringFormatter::EventStringFormatter()
{
}

EventStringFormatter::~EventStringFormatter()
{
}

void EventStringFormatter::setFilter(Filter::ConstPtr filter)
{
  filter_ = filter;
}

std::string EventStringFormatter::format(Timeline::ConstPtr events) const
{
  std::stringstream ss;
  int indent = 0;
  for (Timeline::const_iterator event_it = events->begin(); event_it != events->end(); event_it++)
  {
    Activity::ConstPtr activity = event_it->second;
    if (filter_->exclude(activity))
    {
      continue;
    }
    const Event& e = event_it->first;
    if (e.type == Event::ACTIVITY_START)
    {
      for (int i = 0; i < indent; i++)
      {
        ss << " ";
      }
      ss << "+ ";
      ss << activity->getDescription();
      indent++;
    }
    else
    {
      indent--;
      for (int i = 0; i < indent; i++)
      {
        ss << " ";
      }
      ss << "- ";
      ss << activity->getDescription();
      if (activity->usesWallTimeOnly())
      {
        ss << " ("<<activity->getWallDuration()<<")";
      }
      else
      {
        ss << " ("<<activity->getDuration()<<" * "<<activity->getDuration().toSec()/activity->getWallDuration().toSec()<<")";
      }
    }
  }
  return ss.str();
}

} /* namespace activity_monitoring */
