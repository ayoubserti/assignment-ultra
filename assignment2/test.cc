/*
    @author     Ayoub Serti
    @abstract   testsuite for the second assignment
*/

#include "largest_sum.h"
#include <assert.h>
#include <string>


uint32_t test_find_largest_sum(const set_t& I, uint32_t T)
{
    set_t M;
    uint32_t S;
    find_largest_sum(T,I,M,S);
    assert(S==std::accumulate(M.begin(),M.end(),0));
    return S;
}

#if GENERATE_BIG_TEST
void generate_big_testsuite
{
        std::ofstream   outfile;
        outfile.open("big_test.in");
        for ( uint32_t i =0; i < 10000; ++i){
            outfile << i+1 << " " ;
        }
        outfile << std::endl;
        set_t test_sum { 50 ,12568, 986524, 68457,236514 };
        for ( auto&& c : test_sum)
        {
            outfile << c  << std::endl;
        }
        outfile.close();
}
 #endif


int main( int argv ,char** argc)
{

    //elementary validation
    {
        set_t elems {1,2,3,7,4,5,6};
        set_t M;
        uint32_t S;
        find_largest_sum(11, elems,M, S);
        std::cout << "Maximum: " << S << std::endl;
        for ( auto&& i : M)
            std::cout << i  << " ";
        std::cout << std::endl;
    }

    //test from `test.in`
    {
        std::ifstream infile;
        std::ofstream   outfile;
        infile.open ("test.in");
        outfile.open("test.out");
        if ( infile.is_open() && outfile.is_open() ) 
        {
            while(!infile.eof()){
                uint32_t T;
                uint32_t len;
                infile >> T;
                infile >> len;
                set_t I;
                I.reserve(len);
                while(len>0)
                {
                    uint32_t n;
                    infile >> n;
                    I.push_back(n);
                    len--;
                }
                outfile << test_find_largest_sum(I,T) << std::endl;
            }
            //close streams
            infile.close();
            outfile.close();
        }
    }

    #if GENERATE_BIG_TEST
    generate_big_testsuite(); 
    #endif
   
    //test from `big_test_in`
    {
        std::ifstream   infile;
        std::ofstream   outfile;
        
        infile.open ("big_test.in");
        outfile.open("big_test.out");
        if ( infile.is_open() && outfile.is_open() ) 
        {
            uint32_t T;
            uint32_t len = 10000;
            
            set_t I;
            while(len>0)
            {
                uint32_t n;
                infile >> n;
                I.push_back(n);
                len--;
            }

            while (!infile.eof())
            {
                infile >> T;
                outfile << test_find_largest_sum(I,T) << std::endl;
            }
            //close streams
            infile.close();
            outfile.close();
        }
    }
    
    return 0;
}

