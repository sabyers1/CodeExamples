#include <iostream>
#include <string>
#include <map>

void display_sizes(const std::map<int, int> &nums1,
                   const std::map<int, int> &nums2,
                   const std::map<int, int> &nums3)
{
    std::cout << "nums1: " << nums1.size() 
              << " nums2: " << nums2.size()
              << " nums3: " << nums3.size() << '\n';
    
    std::cout << "N1 ";
    for (auto a : nums1)
        std::cout << a.first << ":" << a.second << " ";
    std::cout << std::endl << "N2 ";
    for (auto a : nums2)
        std::cout << a.first << ":" << a.second << " ";
    std::cout << std::endl << "N3 ";
    for (auto a : nums3)
        std::cout << a.first << ":" << a.second << " ";
    std::cout << std::endl;

}
 
int show_displays()
{
    std::map<int, int> nums1 {{3, 1}, {4, 1}, {5, 9}, 
                              {6, 1}, {7, 1}, {8, 9}};
    std::map<int, int> nums2; 
    std::map<int, int> nums3;
 
    std::cout << "Initially:\n";
    display_sizes(nums1, nums2, nums3);
 
    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;
 
    std::cout << "After assigment:\n"; 
    display_sizes(nums1, nums2, nums3);
 
    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3 = std::move(nums1);
 
    std::cout << "After move assigment:\n"; 
    display_sizes(nums1, nums2, nums3);

    return 0;
}

int main()
{
    std::map <std::string, int> data{
     { "Bobs score", 10 },
     { "Martys score", 15 },
     { "Mehmets score", 34 },
     { "Rockys score", 22 },
     { "Rockys score", 23 } /*overwrites the 22 as keys are identical */
    };
    
    // Iterate over the map and print out all key/value pairs.
    for (const auto& element : data)
    {
        std::cout << "Who(key = first): " << element.first;
        std::cout << " Score(value = second): " << element.second << '\n';
    }

    show_displays();

    return 0;
}