#include <stdio.h>
#include "alert.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

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
