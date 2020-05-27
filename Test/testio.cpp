#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<int> v={1};
    string istr;
    ifstream fin;

    fin.open("tsample.txt");
    while (fin >> istr){
        cout << istr << "*";
        //v.push_back(istr));
    }
    fin.close();
    cout << endl;

    cout << "[ ";
    for(auto x:v){
        cout << x ;
    }
    cout << " ]" << endl << endl;

    return 0;
}