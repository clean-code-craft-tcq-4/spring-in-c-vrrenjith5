/*#include <iostream>



using namespace std;



int main()
{
cout << "Hello world!" << endl;
return 0;
}*/



#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file




#include "catch.hpp"
//#include "stats.h"



#include <stdlib.h>
#include <math.h>



struct Stats{
float average;
float min;
float max;
};



int alertcallcount[2];



struct Stats compute_statistics(const float* numberset, int setlength) {
struct Stats s;
s.average = NAN;
s.min = NAN;
s.max = NAN;



if((numberset != nullptr) && (setlength > 0))
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
//printf("s.average %f ", s.average);
return s;
}




int emailAlerter()
{
static int call_count = 1;
printf("email alert for max");
return call_count;
}



int ledAlerter()
{
static int call_count = 1;
printf("led");
return call_count;
}



typedef int(*pointerToFunction)();



void check_and_alert(float maxthershold, pointerToFunction* funtab, Stats computed)
{
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;



if (computed.max > maxthershold){
emailAlertCallCount = funtab[0]();
printf("doneemail");
ledAlertCallCount = funtab[1]();
printf("donled");
}



alertcallcount[0] = emailAlertCallCount;
printf("printtt");
printf("%d",alertcallcount[0]);
alertcallcount[1] = ledAlertCallCount;
}



TEST_CASE("reports average, minimum and maximum") {
float numberset[] = {1.5, 8.9, 3.2, 4.5};
int setlength = sizeof(numberset) / sizeof(numberset[0]);
struct Stats computedStats = compute_statistics(numberset, setlength);
float epsilon = 0.001;
REQUIRE(abs(computedStats.average - 4.525) < epsilon);
REQUIRE(abs(computedStats.max - 8.9) < epsilon);
REQUIRE(abs(computedStats.min - 1.5) < epsilon);



REQUIRE(isnan(computedStats.average) == false);
REQUIRE(isnan(computedStats.max) == false);
REQUIRE(isnan(computedStats.min) == false);
}



TEST_CASE("average is NaN for empty array") {
printf("hi 1\n");
Stats computedStats = compute_statistics(0, 0);
printf("hi 2\n");



REQUIRE(isnan(computedStats.average) == true);
REQUIRE(isnan(computedStats.max) == true);
REQUIRE(isnan(computedStats.min) == true);



//All fields of computedStats (average, max, min) must be
//NAN (not-a-number), as defined in math.h



//Design the REQUIRE statement here.
//Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
}



TEST_CASE("raises alerts when max is greater than threshold") {
// create additional .c and .h files
// containing the emailAlerter, ledAlerter functions
pointerToFunction alerters[] = {emailAlerter,ledAlerter};



float numberset[] = {99.8, 34.2, 4.5};
int setlength = sizeof(numberset) / sizeof(numberset[0]);
Stats computedStats = compute_statistics(numberset, setlength);



const float maxThreshold = 10.2;
check_and_alert(maxThreshold, alerters, computedStats);
int emailAlertCallCount = alertcallcount[0];
int ledAlertCallCount = alertcallcount[1];



// need a way to check if both emailAlerter, ledAlerter were called
// you can define call-counters along with the functions, as shown below
REQUIRE(emailAlertCallCount == 1);
REQUIRE(ledAlertCallCount == 1);
}
