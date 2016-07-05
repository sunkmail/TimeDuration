/*
Example of 'TimeDuration' Library usage 
        All functions of this library are data processing - no additional hardware is required.
        However, This example DOES use the Serial monitor @ 9600.

This example shows a simple, and virtually pointless, usage of the functions in the TimeDuration Library

*/

#include <TimeDuration.h>

int theTime[5];             // Variable for the duration MUST be an 'int' array with at least 5 positions.  
                            // Data Format: {dd,hh,mm,ss,ms}
                                // used in all functions
                            
String duration;            // a String is needed for human readable output
                                // used in "showTime" function

unsigned long Count;        // a unsigned long is needed for calculating the number of ms in a given duration.
                                // used in "makeTime"


TimeDuration myTime;        // Setup an instance of class TimeDuration

void setup() {
  Serial.begin(9600);       // open the serial port at 9600 bps:
  delay(325);               // Random delay for program to have already had some elapsed time
  
  myTime.startTime();       // Set the TimeDuration start point/time
  delay(234);               // Delay a bit more for stuff to happen  (ie, some real code)
}

void loop() {
  myTime.doTime(theTime);
  duration = myTime.showTime(theTime, 'd', 's');
  Serial.print("Duration from start: ");
  Serial.println(duration);
  
  Count = myTime.makeTime(theTime);               // Convert human readable duration back to total ms of the duration
  Serial.print("re-calculated time in ms: ");
  Serial.println(Count);
  Serial.println();
  

}
