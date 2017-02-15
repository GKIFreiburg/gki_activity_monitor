/*
 * min_duration_filter.h
 *
 *  Created on: Feb 15, 2017
 *      Author: andreas
 */

#ifndef SRC_MIN_DURATION_FILTER_H_
#define SRC_MIN_DURATION_FILTER_H_

#include <gki_activity_monitor/filter.h>

namespace activity_monitoring
{

class MinDurationFilter : public Filter
{
public:
  MinDurationFilter(const ros::WallDuration& duration);
  virtual ~MinDurationFilter();

  virtual bool exclude(Activity::ConstPtr a) const;

private:
  ros::WallDuration duration_;
};

} /* namespace activity_monitoring */

#endif /* SRC_MIN_DURATION_FILTER_H_ */
