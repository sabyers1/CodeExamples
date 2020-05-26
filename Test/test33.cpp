/* Handle all corner cases inluding how zero is represented */
/* Assumes that integers are in range 0 to 100,000 */
// empty sequence, {} = zero;
// write code in C++14 (g++ 6.2.0)

/* Some test corners for solution are:
    zero, zero
    zero, positive
    zero, negative
    positive, zero
    negative, zero
    positive, negative
    positive, positive
    negative, negative
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

std::ostream& operator<< (ostream &out, vector <int> S);

vector<int> solution(vector<int> &A, vector<int> &B) {
    
    vector<int> rvec = {};

    // check for zero (empty) vector return other vector vector
    if(A.size()==0)
        return B;
    else if(B.size()==0)
        return A;

     // convert into base 10
    int a=0;
    for (int i=0; i<(int)A.size();i++){
        a += A[i]*(int)pow(-2.0,i);
    }
    int b=0;
    for (int i=0; i<(int)B.size();i++){
        b += B[i]*(int)pow(-2.0,i);
    }
    
    // sum the value into 'a'
    a += b;

    cout << "debug Answr: "<< a << endl;
    
    // convert 'a' to vector
    //rvec = {};  // empty vector
    if (a == 0)
        return rvec;

    /* To determine number of bits needed to represent value in base -2.
        Consider the vector to be a polynomial expression to represent a
        waveform or frequency.  f(x) = w0*a0 + w1*a1 + w2*a2+...+wN*aN
       there needs to be at least 2 times the value (Nyquist theory) or
       one more bit since base 2 than the value to represent the highest 
       frequency needed to replicate the value.
       val <= 2 * pow(-2.0,i)
       number bits needed = log2(2*val)+1
    */

    int bits = floor(log2(2*a));  // use logrithm base 2 and round up
    cout << "Calc bits: " << bits << " for a=" << a << endl;
    int w = 0; // weight or power of -2
    for (int i=bits; -1 < i; i--){
        w = pow(-2,i);
        if (abs(a) >= abs(a+w))
        {
            a += w;
            //rvec.push_back(1);
            rvec.insert(rvec.begin(),1);
            cout << "w="<< w << "[" << i << "] set+ a = " << a << " v:" << rvec << endl;
        }
        else if (abs(a) >= abs(a-w)){
            a -= w;
            //rvec.push_back(1);
            rvec.insert(rvec.begin(),1);
            cout << "w="<< w << "[" << i << "] set- a = " << a << " v:" << rvec <<endl;
        }
        else
        {
            //rvec.push_back(0);
            rvec.insert(rvec.begin(),0);
            cout << "w="<< w << "[" << i << "] clr  a = " << a << " v:" << rvec << endl;
        }        
    }
    //cout << endl;
    return rvec; 
}

 std::ostream& operator<< (ostream &out, vector <int> S){
    if (S.size()==0)
        out << "{} zero ";
    else {
        for (auto i : S){
            out << i;
        }
    }
    return out;
}

int main(){
    vector<int> A= {0,1,1,0,0,1,0,1,1,1,0,1,0,1,1}; // A = 5730
    vector<int> B= {0,0,1,0,0,1,1,1,1,1,0,1};     // B = -2396
    vector<int> Rs={0,1,0,1,1,0,0,0,1,0,1,1,1};  // Result = 3334
    vector<int> E={}; // zero;

    vector<int> R = solution(A,B);
    
    cout << "Test1 " << (R==Rs?"Correct":"Wrong") << endl;
    cout << "Rs: " << Rs << endl
         << "R : " << R  << endl;

    cout << "Test 2 should be empty"<<endl<< (R=solution(E,E)) << endl;
    cout << "Test 2 " << (R==E?"Correct":"Wrong") << endl;
    cout << "Test 3 should be A:\n" << A << endl << (R=solution(A,E)) << endl;
    cout << "Test 3 " << (R==A?"Correct":"Wrong") << endl;
    cout << "Test 4 should be B:\n" << B << endl << (R=solution(B,E)) << endl;
    cout << "Test 4 " << (R==B?"Correct":"Wrong") << endl;
    cout << "Test 5 should be B:\n" << B << endl << (R=solution(E,B)) << endl;
    cout << "Test 5 " << (R==B?"Correct":"Wrong") << endl;
    cout << "Test 6 should be A:\n" << A << endl << (R=solution(E,A)) << endl;
    cout << "Test 6 " << (R==A?"Correct":"Wrong") << endl;
    return 0;
}