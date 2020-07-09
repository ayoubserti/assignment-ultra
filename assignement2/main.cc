
#include <vector>
#include <algorithm>
   



void find_largest_sum(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t>& M, uint32_t &S)
{
    if ( T == 0)
    {
        S= 0;
        return;
    }
    
    if ( T < *std::min_element(I.begin(), I.end()))
    {
        S = 0;
        return;
    }
    
    if ( *M.rbegin() )



}

int main( int argv ,char** argc)
{



    return 0;
}

