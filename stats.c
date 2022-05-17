#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "stats.h"

int emailAlertCallCount;
int ledAlertCallCount;

Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;
    s.average = NAN;
    s.min = NAN;
    s.max = NAN;

    if((numberset) && (setlength > 0))
    {
     float sum = s.min = s.max = numberset[0];
     for(int i =1; i<setlength; i++) {
      if(s.min > numberset[i]) {
		s.min = numberset[i];
      }
      if(s.max < numberset[i]) {
		s.max = numberset[i];
      }
      sum = sum + numberset[i];
    }
     s.average = sum/setlength;
    }
    return s;
}

void emailAlerter()
{
    emailAlertCallCount ++;
    printf("email alert");
}

void ledAlerter()
{
    ledAlertCallCount ++;
    printf("led alert");
}

void check_and_alert(float maxthershold, alerter_funcptr alerters[], Stats computed)
{
    emailAlertCallCount = 0;
    ledAlertCallCount = 0;
    if (computed.max > maxthershold){
      alerters[0]();
      alerters[1]();
    }
}
