// Treenode.h Definition of class TreeNode
#ifndef TREENODE_H
#define TREENODE_H

// Had to add class signature before template to make friend without redefining.
// not completely sure this is correct, because signature in tree.h
template<class NODETYPE>
class Tree;

template<class NODETYPE>
class TreeNode {
    friend class Tree<NODETYPE>;
    public:
        TreeNode (const NODETYPE &);
        NODETYPE getData() const;
    private:
        TreeNode *leftPtr;
        NODETYPE data;
        TreeNode *rightPtr;
};

// Constructor
template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE &d)
{
    data = d;
    leftPtr = rightPtr = 0;  // initialize as 'leaf' node.
}

// Return a copy of the data value
template<class NODETYPE>
NODETYPE TreeNode<NODETYPE>:: getData() const { return data; }

#endif