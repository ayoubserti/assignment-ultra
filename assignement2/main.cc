
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <string>

//type-define our set  
using set_t = std::vector<uint32_t>;


/*
    @function   recursively_sum_subset 
    @abstract   the recursive function that implement the backtracking algorithm
    @params     
                I                vector of elems
                T                capacity ( optimal sum we are looking for)
                current_set      currently working set 
                current_sum      currently computed sum
                max_set          global set. continuously updated set. we update it every time we found a best solution
                max_sum          global sum. continuously updated sum. we update it every time we found a best solution
                remaining_sum    utility variable to track the whole vector except current peecked element
                level            level in backtracking algorithm, it stand for the tree deep.            
*/
void recursively_sum_subset(const set_t& I, uint32_t T, set_t& current_set, 
                            uint32_t& current_sum, set_t& max_set, 
                            uint32_t& max_sum, uint32_t& remaining_sum, uint32_t level  )
{
    //we reached our maximization.
    if ( max_sum == T) return;
    if ( level == I.size()){
        // We find a new best set
        max_sum = current_sum;
        max_set = current_set;
        return;
    }
    remaining_sum -= I[level];  //remove elem
    if( (current_sum + I[level])<= T)
    {
        // explore the path that contains this item
        current_sum += I[level];
        current_set[level] = 1;  //temporary flag item as peeked
        recursively_sum_subset(I,T,current_set,current_sum,max_set,max_sum,remaining_sum, level +1 );
        current_sum -= I[level]; 
        current_set[level] = 0;//rollback flag
    }
    if (current_sum + remaining_sum > max_sum) { 
        /* There is room for more items */
        recursively_sum_subset(I,  T, current_set, current_sum, 
                max_set, max_sum, remaining_sum, level +1);
    }
    remaining_sum += I[level]; //rollback

}

uint32_t sum_subset( const set_t &I, uint32_t T,  set_t& max_set)
{
    uint32_t current_sum= 0;
    uint32_t max_sum = 0;
    uint32_t remaining_sum = std::accumulate(I.begin(), I.end() , 0);
    set_t current_set(I.size());
    recursively_sum_subset(I,T,current_set,current_sum,max_set,max_sum,remaining_sum,0);
    return max_sum;
}

void find_largest_sum(uint32_t T, const set_t &I, set_t& M, uint32_t &S)
{
    //we deal with unsigned number
    if ( T == 0)
    {
        S = 0;
        return;
    }
    
    //to speed up algorithm, we sort ascthe inputs
    set_t elems = I;
    std::sort(elems.begin(),elems.end(),[](uint32_t a, uint64_t b){
        return a<b;
    });

    //T is less than the minima
    if ( T < *elems.begin())
    {
        S = 0;
        return;
    }

    set_t indexes;
    indexes.reserve(elems.size()); 
    //find the perfect sum and the index of elements in `I` vector
    S = sum_subset(elems, T, indexes);
    if ( S > 0)
    {
        auto i = elems.begin(); 
        for(auto&& j : indexes )
        {
            if ( j >0 )
            {
                M.push_back(*i);
            }
            ++i;
        }
    }

}


uint32_t test_find_largest_sum(const set_t& I, uint32_t T)
{
    set_t M;
    uint32_t S;
    find_largest_sum(T,I,M,S);
    assert(S==std::accumulate(M.begin(),M.end(),0));
    return S;
}

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

        infile.close();
        outfile.close();
    }

    #if GENERATE_BIG_TEST
    
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
   
    //test from `big_test_in`
    {
        std::ifstream infile;
        std::ofstream   outfile;
        infile.open ("big_test.in");
        outfile.open("big_test.out");
        
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
    
        infile.close();
        outfile.close();
    }
    



    return 0;
}

