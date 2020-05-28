#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
using namespace std;

void showVector(vector <int>v){
    for (int x : v)
        std::cout << x << " ";
    std::cout << endl;
}

void inserterTest();

int main(){

    vector <int> vecOfInts(5);  // default vector will be zero.
    array<size_t, 10> g;
    cout << "Size of g is: " << g.size() << endl;

    for (int i = 0; i < vecOfInts.size(); i++)
        vecOfInts[i] = i;

    for (int x : vecOfInts)
        std::cout << x << endl;
    
    copy(vecOfInts.begin(),vecOfInts.end(),
        ostream_iterator <int> (std::cout, " "));
    
    std::cout << " used copy." << endl;

    vector <int> vec2;
    copy(vecOfInts.begin(),vecOfInts.end(),back_inserter(vec2));
    showVector(vec2);

    inserterTest();
    return 0;
}


void inserterTest(){
    std::vector<int> v;
    // can be simplified with back_inserter
    generate_n(std::back_insert_iterator<std::vector<int>>(v),
                    10, [n=0]() mutable { return ++n; });
    for (int n : v){
        std::cout << n << ' ';
    }
    std::cout << endl;
}