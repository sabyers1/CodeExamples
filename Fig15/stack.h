/*
 * File: stack.h
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Template Stack class definitino derived from class xList
 *  
 * -----
 * Last Modified: 30th April 2020 3:57:38 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */

#ifndef STACK_H
#define STACK_H

#include "list.h"


template<class STACKTYPE>
class Stack : private xList<STACKTYPE> {
    public:
        void push(const STACKTYPE &d) { xList<STACKTYPE>::insertAtFront(d); }
        int pop(STACKTYPE &d) { return xList<STACKTYPE>::removeFromFront(d); }
        int isStackEmpty() const { return xList<STACKTYPE>::isEmpty(); }
        void printStack() const { xList<STACKTYPE>::print(); }
};
#endif