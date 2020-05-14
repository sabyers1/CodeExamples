/*
 * File: tree.h
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Definition of template class Tree
 * -----
 * Last Modified: 30th April 2020 4:43:34 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <assert.h>
#include "treenode.h"

template<class NODETYPE>
class Tree {
    public:
        Tree();
        void insertNode(const NODETYPE &);
        void preOrderTraversal() const;
        void inOrderTraversal() const;
        void postOrderTraversal() const;
    private:
        TreeNode<NODETYPE> *rootPtr;

        // Utility functions
        void insertNodeHelper(TreeNode<NODETYPE> **, const NODETYPE &);
        void preOrderHelper(TreeNode<NODETYPE> *) const;
        void inOrderHelper(TreeNode<NODETYPE> *) const;
        void postOrderHelper(TreeNode<NODETYPE> *) const;
};

template<class NODETYPE>
Tree<NODETYPE>::Tree() { rootPtr = 0; }

template<class NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE &value)
    { insertNodeHelper(&rootPtr, value); }

// This function recieves a pointer to a pointer so the pointer can be modified
template<class NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> ** ptr, const NODETYPE &value)
{
    if (*ptr == 0){     // tree is empty
        *ptr = new TreeNode<NODETYPE>(value);
        assert(*ptr != 0);
    }
    else  // tree not empty
        if (value < (*ptr)->data)
            insertNodeHelper( &((*ptr)->leftPtr), value);
        else
            if (value > (*ptr)->data)
                insertNodeHelper( &((*ptr)->rightPtr), value);
            else
                cout << value << " duplicate" << endl;
}

template<class NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const
    { preOrderHelper(rootPtr); }

template<class NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0){
        cout << ptr->data << ' ';
        preOrderHelper(ptr->leftPtr);
        preOrderHelper(ptr->rightPtr);
    }
}

template<class NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const
    { inOrderHelper(rootPtr); }

template<class NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0){
        inOrderHelper(ptr->leftPtr);
        cout << ptr->data << ' ';
        inOrderHelper(ptr->rightPtr);
    }
}

template<class NODETYPE>
void Tree<NODETYPE>::postOrderTraversal() const
    { postOrderHelper(rootPtr); }

template<class NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> *ptr) const
{
    if (ptr != 0){
        postOrderHelper(ptr->leftPtr);
        postOrderHelper(ptr->rightPtr);
        cout << ptr->data << ' ';
    }
}

#endif
