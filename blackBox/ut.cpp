#include <cstdlib>
#include <gtest/gtest.h>
#include "fms.h"
TEST( fmsTest , HandleInput ) {
    char s[]="rate R2D2 2 time 55566 23 12 #";
    char expOutput[] = "rate - identifier\nR2D2 - identifier\n2 - number\ntime - identifier\n55566 - number\n23 - number\n12 - number\n";
    ASSERT_STREQ(expOutput, FMS(s));
    ASSERT_STREQ("@", FMS("@@"));
    ASSERT_STREQ("", FMS("  "));
    ASSERT_STREQ("e@", FMS("e@"));
    ASSERT_STREQ("e1", FMS("e1"));
    ASSERT_STREQ("e_", FMS("e_"));
    ASSERT_STREQ("1_", FMS("1_"));
}
int main( int argc , char **argv ){
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}
