/*
 * File: fig15_8.cpp
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Application to test the template Stack class
 *  
 * -----
 * Last Modified: 30th April 2020 4:04:03 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */

#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> intStack;
    int popInteger;
    cout << "processing an integer Stack"<< endl;

    for (int i = 0; i< 4; i++){
        intStack.push(i);
        intStack.printStack();
    }

    while (!intStack.isStackEmpty()){
        intStack.pop(popInteger);
        cout << popInteger << " popped form stack" << endl;
        intStack.printStack();
    }

    Stack<float> floatStack;
    float val = 1.1, popFloat;

    cout << "processing a float Stack" << endl;

    for (int i=0; i<4; i++){
        floatStack.push(val);
        floatStack.printStack();
        val += 1.1;
    }

    while (!floatStack.isStackEmpty()){
        floatStack.pop(popFloat);
        cout << popFloat << " popped from the stack" << endl;
        floatStack.printStack();
    }
    return 0;
}