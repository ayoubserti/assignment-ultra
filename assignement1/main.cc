/*
    @author     Ayoub Serti
    @abstract   testsuite for the first assignement
*/

#include <iostream>
#include "add.h"
#include <assert.h>


// add function tester
template<typename T>
void test_add(T a, T b )
{   
    assert(add(a,b) == a+b );
}


int main( int argc, char** argv)
{
    //manual validation
    {
        int a = -12, b = -18;
        std::cout   << add ( a , b ) << "   " << a+b << std::endl;
    }
    //manual validation
    {
        char a = 12 ,  b = -18;
        std::cout   << (int)add ( a , b ) << "   " << a+b << std::endl; //char is interpreted by (ostream)std::cout as printable character
    }
    
    //add ( 0.2548 , 152.6552);//  shouldn't compile. we aren't dealing with floating point

    //visual try
    std::cout   << add ( 3 ,5 ) << "   " << 3+5 << std::endl;
    std::cout   << add ( 0 ,5 ) << "   " << 0+5 << std::endl;
    std::cout   << add ( 158 ,2635 ) << "   " << 158+2635 << std::endl;
    std::cout   << add ( 300 ,965 ) << "   " << 300+965 << std::endl;
    std::cout   << add ( 68512 ,69854 ) << "   " << 68512+69854 << std::endl;

    //arbitary tests
    test_add(2580,0);
    test_add(-1,8522);

    //test with uint64 limit
    {
        uint64_t a= std::numeric_limits<uint64_t>::max() , b=2;
        test_add(a,b);
    }

    //test with int64 limit
    {
        int64_t a= std::numeric_limits<int64_t>::max() , b=b=std::numeric_limits<int64_t>::min();
        test_add(a,b);
    }

    //test with int32 limit
    {
        int32_t a= std::numeric_limits<int32_t>::max() , b=std::numeric_limits<int32_t>::min();
        test_add(a,b);
    }

    //test with uint32 limits
    {
        uint32_t a= std::numeric_limits<uint32_t>::max() , b=std::numeric_limits<uint32_t>::min();
        test_add(a,b);
    }

    return 0;
}