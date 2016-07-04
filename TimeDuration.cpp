// TimeDuration V0.0 - Scott Mitten  sunkmail@gmail.com

#include "TimeDuration.h"

const unsigned long OneDay = 86400000;
const unsigned long OneHour = 3600000;
const unsigned long OneMin = 60000;
const unsigned long OneSecond = 1000;

unsigned long timeStart;
int duration[4];
int setDuration[4];


//<<constructor>>
TimeDuration::TimeDuration()
{
  startTime();    // sets baseline time, if not called later.
  /* Nothing else to Construct */
}

//<<destructor>>
TimeDuration::~TimeDuration()
{
  /* Nothing to destruct */
}


// ************************ startTime ******************************************


// Baseline the Start of the TimeDuration count, OR reset duration back to zero

void TimeDuration::startTime()
{
  timeStart = millis();
}



// ************************ doTime ******************************************



// Figure out how long has past since timeStart and return a Byte array in format [dd,hh,mm,ss,ms]
void TimeDuration::doTime(int duration[4])
{
  unsigned long elapsed;
  elapsed = (millis() - timeStart);

  if (elapsed >= OneDay)
  {
    duration[0] = elapsed / OneDay;         // determine how many full days in number
    elapsed = elapsed - (duration[0] * OneDay); // Removes full days, so TIME is less than 1 Day
  }
  if (elapsed >= OneHour)
  {
    duration[1] = elapsed / OneHour;         // determine how many full hours in number
    elapsed = elapsed - (duration[1] * OneHour); // Removes full hours, so TIME is less than 1 Hour
  }
  if (Time >= OneMin)
  {
    duration[2] = elapsed / OneMin;         // determine how many full mins in number
    elapsed = elapsed - (duration[2] * OneMin); // Removes full mins, so TIME is less than 1 min
  }
  if (elapsed >= OneSecond)
  {
    duration[3] = elapsed / OneSecond;         // determine how many full days in number
    duration[4] = elapsed - (duration[3] * OneSecond); // Removes full mins, so TIME is less than 1 min
    // Less than full seconds not used on display, no more math needed
  }
  return duration[];
}


// ************************ showTime - 1, 2 Or 3 Variable ******************************************


// Create a string with the current duration in format"dd:hh:mm:ss.ms"
// Can be sent directly to displays without further formatting

//  Variable format:  Data Array, first item to display ('d','h','m','s'), Last item to display ('d','h','m','s')

//  first item's display rolls-over to after the prior item's number would increment
//  ie.  'h' rolls back to Zero after 23:59:59.999, rather than going to 24, 25, 26, ... 
//       Especially important with 'm' & 's' - They roll-over after 60 'units'
//  ****  ^^^^ To Fix future update!  ^^^^ *********

//  if 'first' variable used, and other than ('d','h','m','s'), "VAR Error!" is returned .
//  if 'last' variable other than ('d','h','m','s'), up to (and including) ms shown

// If only one item and lower (including ms) are desired, function can be called as:
//  showTime(int array, char first = 'char of interest');     Result will show all down to ms
//    ie. showTime(int array, char first = 'h');     results in hh:mm:ss.ms


String TimeDuration::showTime(int duration[], char first = 'd', char last)
{
  String displayTime;

  switch first = 'd'                     // Start at the 'first' variable desired
{
  case 'd':
    if (duration[0] < 10)         //if Days <10, add a leading zero
        DisplayTime = "0";
      DisplayTime += duration[0];
      if (last == 'd')
        break;
      DisplayTime += ":";

    case 'h':
      if (duration[1] < 10)         // hours
        DisplayTime += "0";
      DisplayTime += duration[1];
      if (last == 'h')
        break;
      DisplayTime += ":";

    case 'm':
      if (duration[2] < 10)
        DisplayTime += "0";
      DisplayTime += duration[2];   // mins
      if (last == 'm')
        break;
      DisplayTime += ":";

    case 's':
      if (duration[3] < 10)         // seconds
        DisplayTime += "0";
      DisplayTime += duration[3];
      if (last == 's')
        break;
      DisplayTime += ".";

      if (duration[4] < 100)         // milli-seconds
        DisplayTime += "0";
      else if (duration[4] < 10)
        DisplayTime += "00";

      DisplayTime += duration[4];
      break;

     default:
     DisplayTime = "VAR Error!";
  }

  return DisplayTime;

}


// ************************ makeTime ******************************************

// Convert a duration array[4] with format (dd,hh,mm,ss,ms) to the number of ms for that duration



unsigned long TimeDuration::makeTime(int setDuration[])
{
  unsigned long makeMillis;

  makeMillis = ((setDuration[0] * OneDay) + (setDuration[1] * OneHour) + (setDuration[2] * OneMin) + (setDuration[3] * OneSecond) + setDuration[4]);

  return makeMillis;
}






