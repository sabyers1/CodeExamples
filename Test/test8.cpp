#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
        if (&root == nullptr){
            cout << "Null root found,so false" << endl;
            return false;
        }

        int compareV = root.getValue(); //should be equal or larger than left nodes
        if (compareV == value){
            cout << "Found "<< value << endl;
            return true;
        }
        if (compareV < value){
            cout << "Searching rightside "<<compareV<<" < "<< value<<endl;
            return contains(*root.getRight(),value);
        }
        if (compareV > value){
            cout << "Searching left side "<<compareV<<" > "<< value<<endl;
            return contains(*root.getLeft(),value);
        }
    }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n4(4, NULL, NULL);
    Node n3(3, NULL, &n4);
    Node n2(2, &n1, &n3);

    std::cout << BinarySearchTree::contains(n2, 3)<< std::endl;
    std::cout << BinarySearchTree::contains(n2, 4)<< std::endl;
    std::cout << BinarySearchTree::contains(n2, 0)<< std::endl;
    std::cout << BinarySearchTree::contains(n2, 1)<< std::endl;

}
#endif