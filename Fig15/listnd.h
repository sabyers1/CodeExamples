// LISTND.H
// Listnode template definition
#ifndef LISTND_H
#define LISTND_H

// Had to add xList class signature before ListNode template to make friend without redefining.
// not completely sure this is correct, because signature in list.h
template<class NODETYPE>
class xList;

template<class NODETYPE>
class ListNode {
    public:
        friend class xList<NODETYPE>;  //make List a friend
        ListNode(const NODETYPE &); // constructor
        NODETYPE getData() const;   // return the data in the node
    private:
        NODETYPE data;              // data
        ListNode *nextPtr;          // next node in the list
};

// Constructor
template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
{
    data = info;
    nextPtr = 0;
}

// Return a copy of the data in the node
template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const { return data; }
#endif
