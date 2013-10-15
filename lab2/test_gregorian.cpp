#include <cxxtest/TestSuite.h>
#include "gregorian.h"

class GregorianTestSuite : public CxxTest::TestSuite
{
public:
  void test_initializing( void )
  {
    lab2::Gregorian g(2013,10,3);
    TS_ASSERT_EQUALS(g.year(), 2013);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 3);
  }

  void test_add_day( void )
  {
    lab2::Gregorian g(2013, 10, 3);
    ++g;
    TS_ASSERT_EQUALS(g.day(), 4);
  }
};
