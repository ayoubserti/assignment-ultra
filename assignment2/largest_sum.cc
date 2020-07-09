#include "largest_sum.h"

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
static void recursively_sum_subset(const set_t& I, uint32_t T, set_t& current_set, 
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

static uint32_t sum_subset( const set_t &I, uint32_t T,  set_t& max_set)
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