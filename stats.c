#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "stats.h"

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

void check_and_alert(float maxthershold, alerter_funcptr alerters[], Stats computed)
{
    if (computed.max > maxthershold){
      alerters[0]();
      alerters[1]();
    }
}
