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
#include <gki_activity_monitor/event_iterator.h>

namespace activity_monitoring
{

struct ActivityStartComparator
{
  bool operator()(Activity::ConstPtr a, Activity::ConstPtr b)
  {
    if (a->getId() == b->getId())
    {
      return false;
    }
    return a->getStartWallTime() < b->getStartWallTime();
  }
};

struct ActivityFinishComparator
{
  bool operator()(Activity::ConstPtr a, Activity::ConstPtr b)
  {
    if (a->getId() == b->getId())
    {
      return false;
    }
    return a->getFinishWallTime() < b->getFinishWallTime();
  }
};

class Timeline
{
public:
  typedef boost::shared_ptr<Timeline> Ptr;
  typedef boost::shared_ptr<Timeline const> ConstPtr;
  typedef std::set<Activity::ConstPtr> ActivitySet;
  typedef std::set<Activity::ConstPtr, ActivityStartComparator> StartedActivitySet;
  typedef std::set<Activity::ConstPtr, ActivityFinishComparator> FinishedActivitySet;

  Timeline();
  virtual ~Timeline();

  void insert(Activity::ConstPtr a);
  size_t erase(Activity::ConstPtr a);
  void clear();

  const StartedActivitySet& getStartedActivities() const;
  const FinishedActivitySet& getFinishedActivities() const;

//  EventIterator begin() const;
//  EventIterator end() const;

private:
  StartedActivitySet started_;
  FinishedActivitySet finished_;
};

} /* namespace activity_monitoring */

#endif /* SRC_ACTIVITY_TIMELINE_H_ */
