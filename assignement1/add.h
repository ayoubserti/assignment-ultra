/*
    @author Ayoub Serti
    @abstract Use bit operator to calculate the sum of two integers, check overflow with bit operator too.
*/
#ifndef __ADD_HEADERS__
#define __ADD_HEADERS__

#include <type_traits>  //used of enable_if
#include <limits>       // numerics_limits


/*
    function template to calculation the sum of two integers
    The idea behind function template is to support every integer-type 
    and forbiden calls to no-integer such as double or float.
    So the compiler notify as when trying to call for instance 
                add ( 0.2548 , 152.6552);

    **Note**: since we are additioning bit by bit we don't care about sign. Litteraly we are doing a hardware emulation 
*/
template<typename T>
typename std::enable_if<std::numeric_limits<T>::is_integer, T>::type 
add(T a , T b)
{
    T r ,c, mask;
    // *r*      result
    // *c*      carry of last addition
    // *mask*   the binary mask ( new carry )
    
    c =a & b; //first calculate initial carry 
    r = a ^ b;  //initial value of result; we use xor as it's a binary addition

    /*
        for instance: 3 + 5
        3 --------------> 011
        5 --------------> 101
        -------------------------
                            0   c=10
                           00   c=010
                          000   c=100
                         1000   c=0

        0-              c = 001 , r = 110 
        1- mask = 010 , c = 010 , r = 100
        2- mask = 100 , c = 100 , r = 0
        3- mask =1000 , c = 0   , r = 1000
        4- <break>

    */
    while(c != 0)
    {
        mask = c << 1;  //compute new mask by shifting the carry.
        c = r & mask;   // recompute the carry 
        r = r ^ mask;   // recompute the result
    }   
    return r;
}

// pseudo specialization to forbid floating-point additioning 
template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type 
add(T a , T b)
{
    static_assert(std::numeric_limits<T>::is_integer, "floating point not supported");
    return 0;
}
#endif