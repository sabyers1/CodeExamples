#include <bits/stdc++.h>
#include <string>

using namespace std;
/* Function returns the lowest value in vector that is not
   found in the vector items which is greater than zero.
*/
int solution(vector <int>& A){
    int lowVal = 1;

    sort(A.begin(),A.end());

    for (int i=0;i<A.size();i++){
        if(A[i]==lowVal)
            lowVal++;
    }
    return lowVal;
}

// Converts vector with integers into a string for output
string vtos(vector <int>v){
    std::stringstream result;
    std::copy(v.begin(),v.end(),std::ostream_iterator<int>(result, " "));
    return result.str();
}

int main(){
    vector <int> A = {-1,-3};
    vector <int> B = {1,3,4,6,1};
    vector <int> C = {1,5,2,7,3};

    cout << "Array A " << vtos(A) << " solution is: "<< solution(A) << endl;
    cout << "Array B " << vtos(B) << " solution is: "<< solution(B) << endl;
    cout << "Array C " << vtos(C) << " solution is: "<< solution(C) << endl;

    cout << "All arrays: " << vtos(A)<<", "<<vtos(B)<<", "<<vtos(C)
            << endl;
    return 0;
}