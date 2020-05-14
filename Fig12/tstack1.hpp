// TSTACK1.HPP
// Simple template class Stack
#ifndef TSTACK1_HPP
#define TSTACK1_HPP
#include <iostream>

template<class T>
class Stack {
    public:
        Stack(int = 10);                // default constructor (stack size 10)
        ~Stack(){ delete [] stackPtr; }  // destructor
        int push(const T&);     // push an element onto the Stack
        int pop (T&);           // pop an element from the Stack
        int isEmpty() const { return top == -1; }  // 1 if empty
        int isFull() const { return top == size - 1; }   // 1 if full
    private:
        int size;       // # f elements in the stack
        int top;        // locations of the top element
        T *stackPtr;    // pointer to the stack
};

// Constructor with default size 10
template<class T>
Stack<T>::Stack(int s)
{
    size = s > 0 && s < 1000 ? s : 10; // reasonable size
    top = -1;   // Stack is initially empty
    stackPtr = new T[size];     // space allocated for Stack elements
}
// Push an element onto the stack
// Return 1 if successful, 0 otherwise
template<class T>
int Stack<T>::push(const T &item)
{
    if (!isFull()){
        stackPtr[++top] = item;     // place item in Stack
        return 1;                   // push successful
    }
    return 0;                       // push unsuccessful
}

template<class T>
int Stack<T>::pop(T &popValue)
{
    if(!isEmpty()){
        popValue = stackPtr[top--];  // remve item from Stack
        return 1;   // pop successful
    }
    return 0;       // pop unsuccessful
}

#endif