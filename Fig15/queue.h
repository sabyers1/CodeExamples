/*
 * File: queue.h
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Template Queue class definition (derived from class list)
 *  
 * -----
 * Last Modified: 30th April 2020 4:18:37 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */


#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

template<class QUEUETYPE>
class Queue : private xList<QUEUETYPE>{
    public:
        void enqueue (const QUEUETYPE &d) { xList<QUEUETYPE>::insertAtBack(d); }
        int dequeue(QUEUETYPE &d) { return xList<QUEUETYPE>::removeFromFront(d); }
        int isQueueEmpty() const { return xList<QUEUETYPE>::isEmpty(); }
        void printQueue() const { xList<QUEUETYPE>::print();}
    private:
};

#endif