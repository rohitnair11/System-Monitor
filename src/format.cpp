#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
  char time[10];
  int hours = seconds/3600;
  int rem = seconds%3600;
  int mins = rem/60;
  int secs = rem%60;
  sprintf(time, "%.2d:%.2d:%.2d", hours, mins, secs);
  return time;
}