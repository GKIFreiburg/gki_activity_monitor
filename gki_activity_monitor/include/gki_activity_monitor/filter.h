/*
 * Filter.h
 *
 *  Created on: Feb 15, 2017
 *      Author: andreas
 */

#ifndef INCLUDE_GKI_ACTIVITY_MONITOR_FILTER_H_
#define INCLUDE_GKI_ACTIVITY_MONITOR_FILTER_H_

#include <boost/shared_ptr.hpp>
#include <gki_activity_monitor/activity.h>

namespace activity_monitoring
{

class Filter
{
public:
  typedef boost::shared_ptr<Filter> Ptr;
  typedef boost::shared_ptr<Filter const> ConstPtr;

  virtual bool exclude(Activity::ConstPtr a) const = 0 ;
};

} /* namespace activity_monitoring */

#endif /* INCLUDE_GKI_ACTIVITY_MONITOR_FILTER_H_ */
