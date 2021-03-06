#ifndef __STATS_H
#define __STATS_H

struct Stats{
  float average;
  float min;
  float max;
};

Stats compute_statistics(const float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert(float maxthershold, alerter_funcptr alerters[], Stats computed);
extern int emailAlertCallCount;
extern int ledAlertCallCount;

#endif
