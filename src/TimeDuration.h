// TimeDuration V0.0.1-beta - Scott Mitten  sunkmail@gmail.com

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
  void startOfTime();
  void doingTime(int _duration[]);
  String showTime(int _duration[], char _first, char _last);  //see .cpp file for 'char' usage
  unsigned long makeTime(int setDuration[]);
  //for next function names ?? :)
  // onTime()  
  // outtaTime()
  
  // compare duration function - make 2, one set for ms, one for data array
 
  private:
  unsigned long _timeStart;
  int _duration[];
  int _setDuration[];  
  unsigned long _makeMillis;
  char _first;
  char _last;

};


#endif
