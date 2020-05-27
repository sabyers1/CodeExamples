#include <iostream>
#include <vector>
using namespace std;

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::vector <std::string> srcList = names1;
    std::vector <std::string> cmpList = names2;
    std::vector <std::string> uniqueList;

    /*
     case 1: name in src list only
     case 2: name duplicated in src list
     case 3: name duplicated in cmp list
     case 4: name in cmp list only
     */

    // sort list to enable removing duplicates
    std::sort (srcList.begin(), srcList.end());
    
    std::sort (cmpList.begin(), cmpList.end());

    // iterate through list and remove duplicates
    std::vector<std::string>::iterator it = srcList.begin();
    std::vector<std::string>::iterator nxtit = it;
    for (; it<srcList.end(); it++){
        nxtit++;  /* next item in vector */
        if (*nxtit == *it)
            srcList.erase(nxtit);
    }
    std::cout << "Sorted and erased: \n";
    for(auto element : srcList)
        {
        std::cout << element << ' '; 
        } 

    return uniqueList;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Emma","Ava", "Emma", "Olivia","Emma"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};
    
    std::cout << "Unique Names: \n";
    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
    std::cout << std::endl << std::endl;

    return 0;
}
#endif