// list.h
// Template List class definition
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <assert.h>
using namespace std;
#include "listnd.h"

template<class NODETYPE>
class xList {
    public:
        xList();     // constructor
        ~xList();    // destructor
        void insertAtFront(const NODETYPE &);
        void insertAtBack(const NODETYPE &);
        int removeFromFront(NODETYPE &);
        int removeFromBack(NODETYPE &);
        int isEmpty() const;
        void print() const;
    private:
        ListNode<NODETYPE> *firstPtr;    // pointer to first node
        ListNode<NODETYPE> *lastPtr;    // pointer to last node
        ListNode<NODETYPE> *getNewNode(const NODETYPE &);    // utility
};

// Default constructor
template<class NODETYPE>
xList<NODETYPE>::xList() { firstPtr = lastPtr = 0; }

// Destructor
template<class NODETYPE>
xList<NODETYPE>::~xList() 
{
    if (!isEmpty()) {  // List is not empty
        cout << "Destroying nodes ..." << endl;

        ListNode<NODETYPE> *currentPtr = firstPtr, *tempPtr;

        while (currentPtr != 0){
            tempPtr = currentPtr;
            cout << tempPtr->data << endl;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
    cout << "All nodes destroyed" << endl << endl;
} 

// Insert a node at the front of the list
template<class NODETYPE>
void xList<NODETYPE>::insertAtFront(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if(isEmpty())
        firstPtr = lastPtr = newPtr;
    else        // List is not empty
    {
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }
    
}

// Insert a node at the back of the list
template<class NODETYPE>
void xList<NODETYPE>::insertAtBack(const NODETYPE &value)
{
    ListNode<NODETYPE> *newPtr = getNewNode(value);

    if(isEmpty())
        firstPtr = lastPtr = newPtr;
    else        // List is not empty
    {
        lastPtr->nextPtr = newPtr;
        lastPtr = newPtr;
    }
    
}

// Delete a node from the front of the list
template<class NODETYPE>
int xList<NODETYPE>::removeFromFront(NODETYPE &value)
{
    if (isEmpty())     // List is empty
        return 0;
    else {          // List is not empty
        ListNode<NODETYPE> *tempPtr = firstPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
            firstPtr = firstPtr->nextPtr;
        
        value = tempPtr->data;      // data being removed
        delete tempPtr;
        return 1;
    }
}

// Delete a node from the back of the list
template<class NODETYPE>
int xList<NODETYPE>::removeFromBack(NODETYPE &value)
{
    if (isEmpty())     // List is empty
        return 0;       // delete unsuccessful
    else {          // List is not empty
        ListNode<NODETYPE> *tempPtr = lastPtr;

        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else {
            ListNode<NODETYPE> *currentPtr = firstPtr;

            while( currentPtr->nextPtr != lastPtr){
                currentPtr = currentPtr->nextPtr;
            }
            lastPtr = currentPtr;
            currentPtr->nextPtr = 0;
        }
        
        value = tempPtr->data;      // data being removed
        delete tempPtr;
        return 1;                   // delete successful
    }
}

// Is list empty?
template<class NODETYPE>
int xList<NODETYPE>::isEmpty() const { return firstPtr == 0; }

// Return a pointer to a newly allocated node.
template<class NODETYPE>
ListNode<NODETYPE> *xList<NODETYPE>::getNewNode(const NODETYPE &value)
{
    ListNode<NODETYPE> *ptr = new ListNode<NODETYPE> (value);
    assert(ptr!=0);     // verify memory allocated
    return ptr;
}

// Display contents of list
template<class NODETYPE>
void xList<NODETYPE>::print() const{
    if(isEmpty()){
        cout << "The list is empty." << endl << endl;
        return;
    }

    ListNode<NODETYPE> *currentPtr = firstPtr;
    cout << "The list is: ";
    while (currentPtr != 0){
        cout << currentPtr->data << " ";
        currentPtr = currentPtr->nextPtr;
    }
    cout << endl << endl;
}
#endif