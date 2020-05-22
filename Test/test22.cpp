#include <stdexcept>
#include <iostream>
#include <vector>

/* Fix bugs in code.  method must throw... for illegal value or combination
*/

double mean(const std::vector<int>& numbers, const std::vector<int>& weights)
{
    int total = 0;
    int totalWeights = 0;

    if(numbers.size()!= weights.size())
        throw std::invalid_argument("Argument exception.");

    try{    
        for (size_t i = 0; i < numbers.size(); i++){
            total += abs(numbers[i] * weights[i]);
            totalWeights += abs(weights[i]);
            }
    } catch (std::exception e){
        throw std::invalid_argument("Argument exception.");
    }
    if(totalWeights==0)
        throw std::invalid_argument("Argument exception.");

    return total / totalWeights;
}

#ifndef RunTests
int main()
{
    std::vector<int> a, b;
    a.push_back(3);
    a.push_back(6);
    b.push_back(4);
    b.push_back(2);
    std::cout << mean(a, b);
}
#endif