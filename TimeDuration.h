// TimeDuration V0.0 - Scott Mitten  sunkmail@gmail.com

#ifndef TIMEDURATION_H
#define TIMEDURATION_H
 
#include <Arduino.h>

/* Library Limitation:    Cannot (currently) do longer than ~45 Days
 *                        (uses millis() function) 
 *
 */


class TimeDuration {
  public:
  TimeDuration();
  ~TimeDuration();
  void startTime();
  void doTime(int duration);
  String showTime(byte duration, char first, char last);  //see .cpp file for 'char' usage
  unsigned long makeTime(int setDuration[]);

 
  private:
  unsigned long timeStart;
  int duration[4];
  int setDuration[4];  
  unsigned long makeMillis;

};


#endif
