/*
 * event_string_formatter.h
 *
 *  Created on: Feb 15, 2017
 *      Author: andreas
 */

#ifndef SRC_EVENT_STRING_FORMATTER_H_
#define SRC_EVENT_STRING_FORMATTER_H_

#include <gki_activity_monitor/filter.h>
#include <gki_activity_monitor/timeline.h>

namespace activity_monitoring
{

class EventStringFormatter
{
public:
  EventStringFormatter();
  virtual ~EventStringFormatter();

  void setFilter(Filter::ConstPtr filter);

  std::string format(Timeline::ConstPtr events) const;

private:
  Filter::ConstPtr filter_;
};

} /* namespace activity_monitoring */

#endif /* SRC_EVENT_STRING_FORMATTER_H_ */
