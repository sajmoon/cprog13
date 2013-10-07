#ifndef DATE_H
#define DATE_H

namespace lab2 {
  class Date;
}
class lab2::Date {
  private:
    int lyear = 0;
    int lmonth = 0;
    int lday = 0;
    int ldays_per_week = 7;
    int lmonth_per_year = 10;

    void subtract_day();
    void add_day();
    void subtract_month();
    void add_month();
  public:
   Date(int m_per_year, int d_per_week, int y, int m, int d);
   int year();
   int month();
   int day();
   int week_day();
   int days_per_week();
   int days_this_month();
   int months_per_year();

   Date & operator++(); // Prefix
   Date & operator--();

   Date & operator-=(int);
   Date & operator+=(int);

   void add_year();
   void subtract_year();
   void add_year(int);
   void subtract_years(int);

};

#endif
