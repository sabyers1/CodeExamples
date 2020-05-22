#include <iostream>
#include <vector>
using namespace std;

class Train {
    vector<int> vec;

public:
    Train(vector<int> v){
        vec = v;
    }
    void addLeft(int wagonID){
        vec.push_back(wagonID);
    }
    void addRight(int wagonID){
        vec.insert(vec.begin(),wagonID);
    }

    int getRight(){
        int wagonID = vec.front();
        vec.erase(vec.begin());
        return wagonID;
    }

    int getLeft(){
        int wagonID = vec.back();
        vec.pop_back();
        return wagonID;
    }
    void print(){
        for (int i=0; i< vec.size();i++)
            cout <<vec[i] << " ";

        cout << endl;
    }
};

int main(){
    // int x = 10;
    // vector<int> vec;
    // for(int i = 1; i<=5;i++)
    //     vec.push_back(i);

    // Train cars(vec);
    // cars.print();

    vector<int> vec;
    Train t(vec);
    
    t.addLeft(7);
    t.addLeft(13);
    cout << t.getRight() << endl; // 7
    cout << t.getLeft() << endl;  // 13

return 0;
}