#include <stdio.h>
#include "alert.h"

int emailAlertCallCount;
int ledAlertCallCount;

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
