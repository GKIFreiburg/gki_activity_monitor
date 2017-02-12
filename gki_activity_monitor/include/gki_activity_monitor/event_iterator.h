/*
 * event_iterator.h
 *
 *  Created on: Feb 12, 2017
 *      Author: andreas
 */

#ifndef SRC_EVENT_ITERATOR_H_
#define SRC_EVENT_ITERATOR_H_

#include <boost/iterator.hpp>
#include <gki_activity_monitor/activity.h>
#include <gki_activity_monitor/timeline.h>

namespace activity_monitoring
{

struct Event
{
  enum Type
  {
    ACTIVITY_START,
    ACTIVITY_FINISH
  };
  Type type_;
  ros::WallTime event_time_;
  Activity::ConstPtr activity_;
};

class EventIterator
{
public:
  EventIterator();
  virtual ~EventIterator();
};

} /* namespace activity_monitoring */

#endif /* SRC_EVENT_ITERATOR_H_ */
