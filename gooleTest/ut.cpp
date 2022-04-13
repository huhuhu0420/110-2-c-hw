#include <cstdlib>
#include <gtest/gtest.h>
#include "bmi.h"
TEST( multest , HandleNoneZeroInput ) {
    ASSERT_EQ( 0 , computeBMI( 0 ,0 ) ) ;
    ASSERT_EQ( 0 , computeBMI( 100 , 0) ) ;
    ASSERT_EQ( -2 , computeBMI( 52 , 100) ) ;
    ASSERT_EQ( -1 , computeBMI( 42 , 155) ) ;
    ASSERT_EQ( 21.64 , computeBMI( 52 , 155) ) ;
}
int main( int argc , char **argv ){
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( );
}
