#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <functional>

int main(){
    std::vector<int> v = {7, 1, 4, 0, -1};

    std::cout << "Before: \n";
    for(auto i : v)
        std::cout << i << ", ";
    std::cout << std::endl;
    std::sort(v.begin(),v.end());   // contrained algorithm

    std::cout << "Sorted: \n";
    for(auto i : v)
        std::cout << i << ", ";
    std::cout << std::endl;

    int sum = std::accumulate(v.begin(),v.end(),0);
    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}
