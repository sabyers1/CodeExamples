/*
 * File: fig12_2.cpp
 * File Create: 29th April 2020
 * Author: H.M. Deitel
 * -----
 *  Template exercise useing functions.
 *  
 * -----
 * Last Modified: 29th April 2020 1:33:59 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */
#include <iostream>
using namespace std;

template<class T>
void printArray(T *array, const int count){
    for (int i = 0; i < count; i++){
        cout << array[i] << " * ";
    }
    cout << endl;
}

int main()
{
    const int aCount = 5, bCount = 7, cCount = 6;
    int a[aCount] = { 1, 2, 3, 4, 5};
    float b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    char c[cCount] = "HELLO"; // 6th position for NULL

    cout << "Array a contains: " << endl;
    printArray(a, aCount);      // integer template function
    cout << "Array b contains: " << endl;
    printArray(b, bCount);      // float template function
    cout << "Array c contains: " << endl;
    printArray(c, cCount);      // char template function

    return 0;
}