#include "julian.h"
#include <stdexcept>
#include <assert.h>
#include <math.h>

#include "kattistime.h"
using namespace lab2;

const int month_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const std::string WEEK_DAY_NAMES[8] = { "", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
const std::string MONTH_NAMES[13] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

Julian::Julian()
  : Date()
{
  // get kattis time.
  time_t mytime;
  k_time(&mytime);

  struct tm *t = gmtime(&mytime);
  int year  = t->tm_year + 1900;
  int month = t->tm_mon + 1;      // m mytimenaderna och dagarna
  int day   = t->tm_mday;         // indexerade fran ETTt k_time(NULL);

  init(year, month, day);
}

Julian::Julian(int y, int m, int d)
  : Date()
{
  init(y, m, d);
}

Julian::Julian(const Date & d) : Date(d) { 
}

Julian::Julian(Date * d) : Date(d) {}

// http://www8.cs.umu.se/~isak/Snippets/jdn.c
void Julian::convert_to_gregorian() {
  
  long jdn = get_jdn();
  long x, z, m, d, y;
  long daysPer400Years = 146097L;
  long fudgedDaysPer4000Years = 1460970L + 31;

  // if (julian < 0)                 /* set Julian flag if auto set */
  //   julian = (jdn <= LASTJULJDN);

  x = jdn + 68569L;
  // if ( julian  )
  // {
  //   x += 38;
  //   daysPer400Years = 146100L;
  //   fudgedDaysPer4000Years = 1461000L + 1;

  // }
  z = 4 * x / daysPer400Years;
  x = x - (daysPer400Years * z + 3) / 4;
  y = 4000 * (x + 1) / fudgedDaysPer4000Years;
  x = x - 1461 * y / 4 + 31;
  m = 80 * x / 2447;
  d = x - 2447 * m / 80;
  x = m / 11;
  m = m + 2 - 12 * x;
  y = 100 * (z - 49) + y + x;

  lyear = (int)y;
  lmonth = (int)m;
  lday = (int)d;
}

int Julian::year() const { return lyear; }

int Julian::month() const { return lmonth; }

int Julian::day() const { return lday; }

void Julian::init(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }

  JDN = convert_to_jdn(y, m, d);
  convert_to_gregorian();
}

long Julian::convert_to_jdn(int Y, int M, int D) const {
  long jdn;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}

long Julian::convert_to_jdn() const {
  return convert_to_jdn(lyear, lmonth, lday);
}

int Julian::get_month_length(int m) const {
  assert(year()>0);
  return get_month_length(year(), m);
}

int Julian::get_month_length(int y, int m) const {
  if (m < 1 || m > 12) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }
  if (m == 2 && leap_year(y)) {
    return 29;
  }

  return month_length[m - 1];
}

bool Julian::leap_year() const {
  return leap_year(year());
}

bool Julian::leap_year(int y) const {
  std::cout << "Julian::leap_year("<<y<<")"<<std::endl;
  if (y%4==0) return true;
  return false;
}

std::string Julian::week_day_name() const {
  return WEEK_DAY_NAMES[week_day()];
}

std::string Julian::month_name() const {
  return MONTH_NAMES[month()];
}

int Julian::days_this_month() const {
  get_month_length(month());
}

void Julian::subtract_month() {
  lmonth--;

  if (lmonth < 1) {
    lmonth = 12;
    lyear--;
  }

  JDN = convert_to_jdn();
}

void Julian::add_month() {
  int m = (lmonth + 1) % 12;

  if (get_month_length(m) < lday) {
    JDN += 30;
    convert_to_gregorian();
  } else {
    lmonth++;
    if (lmonth > 12) {
      lmonth = 1;
      ++lyear;
    }
    JDN = convert_to_jdn();
  }
}

void Julian::add_month(int times) {
  for (int i = 0; i < std::abs(times); i++) {
    if (times > 0) {
      add_month();
    } else {
      subtract_month();
    }
  }
}

void Julian::add_day() {
  JDN++;
  convert_to_gregorian();
}

void Julian::add_day(int days) {
  JDN += days;
  convert_to_gregorian();
}

void Julian::add_year() {
  add_year(1);
}

void Julian::add_year(int y) {
  lyear += y;

  if (month() == 2 && day() == 29 && !leap_year()) {
    lday = 28;
  }

  JDN = convert_to_jdn();
}

long Julian::mod_julian_day() const {
  return this->get_jdn() - 2400001;
}

bool Julian::isValid(int y, int m, int d) const {
  if (m < 0 || d > get_month_length(y, m) || d < 1)
    return false;
  return true;
}

