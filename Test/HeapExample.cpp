#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int myints[] = {10,20,30,5,15};
    vector<int> v(myints,myints+5);
    
    make_heap(v.begin(),v.end());

    for (auto x : v)
        cout << x << (x==v.back() ? "\n" : ", ");

    cout << "initial max heap    :" << v.front() << endl;
    pop_heap(v.begin(),v.end());
    v.pop_back();
    cout << "max heap after pop  :" << v.front() << endl;
    for (auto x : v)
        cout << x << (x==v.back() ? "\n" : ", ");

    v.push_back(99);
    push_heap(v.begin(),v.end());
    cout << "max heap after push :" << v.front() << endl;
    for (auto x : v)
        cout << x << (x==v.back() ? "\n" : ", ");

    sort_heap(v.begin(),v.end());
    cout <<"final sorted range:"<< endl;
    for (auto x : v)
        cout << x << (x==v.back() ? "\n" : ", ");

    return 0;
}