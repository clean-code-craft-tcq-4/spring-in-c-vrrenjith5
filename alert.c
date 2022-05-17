#include "alert.h"

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
