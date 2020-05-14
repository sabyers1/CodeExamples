// fig12_3.cpp
// Test application for Stack template
#include <iostream>
using namespace std;
#include "tstack1.hpp"

int main()
{
    Stack<float> floatStack(5);
    float f = 1.1;
    cout << "Pushing elements onto floatStack" << endl;

    while(floatStack.push(f)){
        cout << f << " ";
        f += 1.1;
    }

    cout << endl << "Stack is full Cannot push " << f << endl
        << endl << "Poping elements from floatStack" << endl;;

    while (floatStack.pop(f))
        cout << f << " ";
    cout << endl << "Stack is empty. Cannot pop anymore." << endl;

    Stack<int> intStack;
    int i = 1;
    cout << endl << "Pushing elements onto intStack" << endl;
     while(intStack.push(i)){
        cout << i << " ";
        i += 1;
    }
   cout << endl << "Stack is full Cannot push " << i << endl
        << endl << "Poping elements from intStack" << endl;;

 while (intStack.pop(i))
        cout << i << " ";
    cout << endl << "Stack is empty. Cannot pop anymore." << endl;


}