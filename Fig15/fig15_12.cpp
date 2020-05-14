/*
 * File: fig15_12.cpp
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Test the template Queue class
 *  
 * -----
 * Last Modified: 30th April 2020 4:24:53 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */
#include <iostream>
#include "queue.h"

int main() {
    Queue<int> intQueue;
    int dequeueInteger;
    cout << "Processing an integer Queue" << endl;

    for (int i=0; i<4; i++){
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    while(!intQueue.isQueueEmpty()){
        intQueue.dequeue(dequeueInteger);
        cout << dequeueInteger << " dequeued" << endl;
        intQueue.printQueue();
    }
    
    Queue<float> floatQueue;
    float val = 1.1, dequeueFloat;

    cout << "Processing a float Queue."<< endl;

    for(int i=0; i<4;i++){
        floatQueue.enqueue(val);
        floatQueue.printQueue();
        val += 1.1;
    }

    while(!floatQueue.isQueueEmpty()){
        floatQueue.dequeue(dequeueFloat);
        cout<< dequeueFloat << " dequeued"<<endl;
        floatQueue.printQueue();
    }

    return 0;

}
