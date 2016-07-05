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
  void doTime(int _duration[]);
  String showTime(int _duration[], char _first, char _last);  //see .cpp file for 'char' usage
  unsigned long makeTime(int setDuration[]);

 
  private:
  unsigned long _timeStart;
  int _duration[4];
  int _setDuration[4];  
  unsigned long _makeMillis;

};


#endif
