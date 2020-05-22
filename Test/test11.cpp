#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    /* double iteration through list to see which permutations equal sum */
    /* solution failed time limit for performance */
    for(int i=0;i<list.size()-1;i++){
        for(int j=i+1;j<list.size();j++){
            if (i!=j && list[i]+list[j]==sum){
                return std::make_pair(i,j);
            }
        }    
    }
    return std::make_pair(-1,-1);
}

#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second << std::endl;
}
#endif