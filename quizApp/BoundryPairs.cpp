/*  BoundryPairs.cpp
 *  Excercise to test std functions with pairs.
 */
#include <iostream>
#include <set>
using namespace std;

 // Function for lower bound
 void findLowerBound(
     std::set<std::pair<int, int> >& arr,
     std::pair<int, int>& p)
     {
         auto low = lower_bound(arr.begin(), arr.end(), p);
         cout << "lower_bound() for array  is: {"
            << (*low).first << ", " << (*low).second <<"}" << endl;
     }

 // Function for upper bound
 void findUpperBound(
     set<pair<int,int> >& arr,
     pair<int, int>& p)
     {
         auto up = upper_bound(arr.begin(), arr.end(), p);
         cout << "upper_bound() for array  is: {"
            << (*up).first << ", " << (*up).second <<"}" << endl;
     }

int main(){

    // Given sorted vector of Pairs
    std::set < pair<int,int> > s;

    s.insert(make_pair(1,2));
    s.insert(make_pair(2,4));
    s.insert(make_pair(3,7));
    s.insert(make_pair(8,9));

    pair<int,int> p = { 3,2 };

    findLowerBound(s, p);

    findUpperBound(s, p);

    return 0;
}
