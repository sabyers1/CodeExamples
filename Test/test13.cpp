#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

/* Implement function countNumbers that accepts a sorted vector of unique integers and,
 efficiently with respect to time used, counts the number of vector elements that are
 less than the parameter lessThan.
For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should 
return 2 because there are two vector elements less than 4.
*/

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
    int count=0;
    for(auto it : sortedVector){
        if (it < lessThan)
            count++;
        else
            break;
    }
    return count;
    
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << "1: " << countNumbers(v, 4) << std::endl;
}
#endif