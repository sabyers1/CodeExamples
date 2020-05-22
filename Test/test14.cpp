// Example program
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v = {8,3,6,2,6};
  int key = 6;
  
  std::vector<int>::iterator itr = std::find(v.begin(),v.end(),key);
  
  if(itr != v.end()){
      std::cout <<"Element found at index "<<
        std::distance(v.begin(),itr)+1 << std::endl;
  } else
    std::cout << "Element not found\n";
    
    return 0;
}