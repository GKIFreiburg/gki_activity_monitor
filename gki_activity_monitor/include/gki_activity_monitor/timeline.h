/*
 * activity_timeline.h
 *
 *  Created on: Feb 11, 2017
 *      Author: andreas
 */

#ifndef SRC_ACTIVITY_TIMELINE_H_
#define SRC_ACTIVITY_TIMELINE_H_

#include <gki_activity_msgs/Activity.h>
#include <gki_activity_monitor/activity.h>

namespace activity_monitoring
{

struct Event
{
  enum Type
  {
    ACTIVITY_START,
    ACTIVITY_FINISH
  };
  Type type;
  ros::WallTime event_time;
  long activity_id;

  static Event start(Activity::ConstPtr a);
  static Event finish(Activity::ConstPtr a);
};

struct EventComparator
{
  bool operator()(const Event& a, const Event& b)
  {
    if (a.activity_id == b.activity_id)
    {
      if (a.type == b.type)
      {
        return false;
      }
    }
    return a.event_time < b.event_time;
  }
};

typedef std::map<Event, Activity::ConstPtr, EventComparator> EventTimelineMap;

class Timeline
{
public:
  typedef boost::shared_ptr<Timeline> Ptr;
  typedef boost::shared_ptr<Timeline const> ConstPtr;
  typedef EventTimelineMap::const_iterator const_iterator;

  Timeline();
  virtual ~Timeline();

  void insert(Activity::ConstPtr a);
  void clear();
  EventTimelineMap::const_iterator begin() const;
  EventTimelineMap::const_iterator end() const;

private:
  EventTimelineMap events_;

};

} /* namespace activity_monitoring */

#endif /* SRC_ACTIVITY_TIMELINE_H_ */
