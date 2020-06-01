/*  BoundryPairs.cpp
 *  Excercise to test std functions with pairs.
 */
#include <iostream>
#include <set>
#include <vector>

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


typedef pair<int, int> pairs;

void display(const set<pairs>& s){
    bool found = false;

    for(auto const &x : s){
        found = true;
        cout << "(" << x.first << ", " << x.second << ")" << " ";
    }
    if (not found){
        cout << "No valid pair found" << endl;
    }
    cout << endl;
}

void testDisplay(){
    vector<int> vect{ 2, 3, 1, 6, 8, 8, 10, 2 };
    set <pairs> s;
    
    /* Make pairs of all even numbers present in array */
    for (int i = 0; i < vect.size(); i++){
        for (int j=i; j<vect.size(); j++) {
            // check for even numbers
            if (vect[i] %2 == 0 && vect[j] % 2 == 0 ){
                // make pairs of even numbers
                pairs x = make_pair(vect[i],vect[j]);
                s.insert(x);  // insert into set.
            }
        }
    }

    cout << "Using set: { ";
    std::copy(vect.begin(),vect.end(),ostream_iterator <int> (std::cout, " "));
    cout << "} list pairs of even numbers:"<< endl;
    display(s);  // display sets
    s.clear();   // clear the set.

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

    testDisplay();

    return 0;
}