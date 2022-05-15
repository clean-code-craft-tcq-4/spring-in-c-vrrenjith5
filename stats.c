#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;  
    float sum = 0;
    sum = s.min = s.max = numberset[0];
    
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
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
