/*
 * scoped_activity.h
 *
 *  Created on: Feb 10, 2017
 *      Author: andreas
 */

#ifndef SRC_SCOPED_ACTIVITY_H_
#define SRC_SCOPED_ACTIVITY_H_

#include <gki_activity_monitor/monitor.h>
#include <gki_activity_monitor/activity.h>

namespace activity_monitoring
{

class ScopedActivity
{
public:
  ScopedActivity(const std::string& description, bool use_wall_time=false);
  virtual ~ScopedActivity();
private:
  Monitor::Ptr monitor_;
  Activity::Ptr activity_;
};

} /* namespace activity_monitoring */

#endif /* SRC_SCOPED_ACTIVITY_H_ */
