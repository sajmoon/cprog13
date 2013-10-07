/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "test_date.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_date.cpp", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_default_constructor_date_now : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_default_constructor_date_now() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test_default_constructor_date_now" ) {}
 void runTest() { suite_MyTestSuite.test_default_constructor_date_now(); }
} testDescription_suite_MyTestSuite_test_default_constructor_date_now;

static class TestDescription_suite_MyTestSuite_test_plusplus_prefix : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_plusplus_prefix() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "test_plusplus_prefix" ) {}
 void runTest() { suite_MyTestSuite.test_plusplus_prefix(); }
} testDescription_suite_MyTestSuite_test_plusplus_prefix;

static class TestDescription_suite_MyTestSuite_test_plusplus_postfix : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_plusplus_postfix() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "test_plusplus_postfix" ) {}
 void runTest() { suite_MyTestSuite.test_plusplus_postfix(); }
} testDescription_suite_MyTestSuite_test_plusplus_postfix;

static class TestDescription_suite_MyTestSuite_test_minnusminus_prefix : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_minnusminus_prefix() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 38, "test_minnusminus_prefix" ) {}
 void runTest() { suite_MyTestSuite.test_minnusminus_prefix(); }
} testDescription_suite_MyTestSuite_test_minnusminus_prefix;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";