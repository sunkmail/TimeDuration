// TimeDuration V0.0 - Scott Mitten  sunkmail@gmail.com

#include "TimeDuration.h"

const unsigned long OneDay = 86400000;
const unsigned long OneHour = 3600000;
const unsigned long OneMin = 60000;
const unsigned long OneSecond = 1000;

unsigned long _timeStart;
int _duration[5];
int _setDuration[5];


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


// Baseline the Start of the TimeDuration count, OR reset _duration back to zero

void TimeDuration::startTime()
{
  _timeStart = millis();
}



// ************************ doTime ******************************************



// Figure out how long has past since timeStart and return a Byte array in format [dd,hh,mm,ss,ms]
void TimeDuration::doTime(int _duration[4])
{
  unsigned long _elapsed;
  _elapsed = (millis() - _timeStart);

  if (_elapsed >= OneDay)
  {
    _duration[0] = _elapsed / OneDay;         // determine how many full days in number
    _elapsed = _elapsed - (_duration[0] * OneDay); // Removes full days, so TIME is less than 1 Day
  }
  if (_elapsed >= OneHour)
  {
    _duration[1] = _elapsed / OneHour;         // determine how many full hours in number
    _elapsed = _elapsed - (_duration[1] * OneHour); // Removes full hours, so TIME is less than 1 Hour
  }
  if (_elapsed >= OneMin)
  {
    _duration[2] = _elapsed / OneMin;         // determine how many full mins in number
    _elapsed = _elapsed - (_duration[2] * OneMin); // Removes full mins, so TIME is less than 1 min
  }
  if (_elapsed >= OneSecond)
  {
    _duration[3] = _elapsed / OneSecond;         // determine how many full days in number
    _duration[4] = _elapsed - (_duration[3] * OneSecond); // Removes full mins, so TIME is less than 1 min
    // Less than full seconds not used on display, no more math needed
  }
  
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
//  if '_last' variable other than ('d','h','m','s'), up to (and including) ms shown

// If only one item and lower (including ms) are desired, function can be called as:
//  showTime(int array, char _first = 'char of interest');     Result will show all down to ms
//    ie. showTime(int array, char _first = 'h');     results in hh:mm:ss.ms


String TimeDuration::showTime(int _duration[], char _first = 'd', char _last = '1')
{
  String _displayTime;

  switch(_first)                   // Start at the 'first' variable desired
{
  case 'd':
    if (_duration[0] < 10)         //if Days <10, add a leading zero
        _displayTime = "0";
      _displayTime += _duration[0];
      if (_last == 'd')
        break;
      _displayTime += ":";

    case 'h':
      if (_duration[1] < 10)         // hours
        _displayTime += "0";
      _displayTime += _duration[1];
      if (_last == 'h')
        break;
      _displayTime += ":";

    case 'm':
      if (_duration[2] < 10)
        _displayTime += "0";
      _displayTime += _duration[2];   // mins
      if (_last == 'm')
        break;
      _displayTime += ":";

    case 's':
      if (_duration[3] < 10)         // seconds
        _displayTime += "0";
      _displayTime += _duration[3];
      if (_last == 's')
        break;
      _displayTime += ".";

      if (_duration[4] < 100)         // milli-seconds
        _displayTime += "0";
      else if (_duration[4] < 10)
        _displayTime += "00";

      _displayTime += _duration[4];
      break;

     default:
     _displayTime = "VAR Error!";
  }

  return _displayTime;

}


// ************************ makeTime ******************************************

// Convert a duration array[4] with format (dd,hh,mm,ss,ms) to the number of ms for that duration



unsigned long TimeDuration::makeTime(int _setDuration[])
{
  unsigned long _makeMillis;

  _makeMillis = ((_setDuration[0] * OneDay) + (_setDuration[1] * OneHour) + (_setDuration[2] * OneMin) + (_setDuration[3] * OneSecond) + _setDuration[4]);

  return _makeMillis;
}


