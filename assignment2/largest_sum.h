/*
    @author     Ayoub Serti
    @abstract   Given an integer (T) and an integer set (I), find a subset (M) that the sum (S) of M's 
                elements is the largest among all subsets of I. S <= T.
*/

#ifndef __LARGEST_SUM_HEADERS__
#define __LARGEST_SUM_HEADERS__
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>

//type-define our set  
using set_t = std::vector<uint32_t>;

/*
    @function   `find_larget_sum`
    @params
                T _in_   maxima we are looking for
                I _in_   Set of elements
                M _out_  Subset which constitute the maxima
                S _out_  largest value we can get
    @return     void 
*/
void find_largest_sum(uint32_t T, const set_t &I, set_t& M, uint32_t &S);


#endif 