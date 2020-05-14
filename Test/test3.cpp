#include <iostream>
#include <map>
#include <utility> // make_pair

int main()
{
    typedef std::map<char, int> MapType;
    MapType my_map;

    // insert elements using insert function
    my_map.insert(std::pair<char, int>('a', 1));
    my_map.insert(std::pair<char, int>('b', 2));
    my_map.insert(std::pair<char, int>('c', 3));
    my_map.insert(MapType::value_type('d', 4)); // all standard containers provide this typedef
    my_map.insert(std::make_pair('e', 5));      // can also use the utility function make_pair
    my_map.insert({'f', 6});                    // using C++11 initializer list
    
    //map keys are sorted automatically from lower to higher. 
    //So, my_map.begin() points to the lowest key value not the key which was inserted first.
    MapType::iterator iter = my_map.begin();

    // erase the first element using the erase function
    my_map.erase(iter);

    // output the size of the map
    std::cout << "Size of my_map: " << my_map.size() << '\n';

    for (auto k : my_map)
        std::cout << k.first << ": " << k.second << std::endl;

    std::cout << "Enter a key to search for: ";
    char c;
    std::cin >> c;

    // find will return an iterator to the matching element if it is found
    // or to the end of the map if the key is not found
    iter = my_map.find(c);
    if (iter != my_map.end() ) 
        std::cout << "Value is: " << iter->second 
        << " for key "<< iter->first << '\n';
    else
        std::cout << "Key " << c << " is not in my_map" << '\n';

    // clear the entries in the map
    my_map.clear();

    return 0;
}