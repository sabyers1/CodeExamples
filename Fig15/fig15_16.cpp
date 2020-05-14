/*
 * File: fig15_16.cpp
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Application to tes class Tree (binary)
 *  
 * -----
 * Last Modified: 30th April 2020 7:03:33 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "tree.h"

#if false
template<typename T, size_t n>
void print_array(T const(& arr)[n]){
    for (size_t i=0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
#else
template<typename T, size_t n>
void print_array(T const(& arr)[n]){
    for (const auto& a: arr)
        cout << a << ' ';
    cout << endl;
}
#endif


int main()
{
    Tree<int> intTree;
    int intVal;
    int iArray[] { 50, 25, 75, 12, 33, 67, 88, 6, 13, 68, 50, 7};

    std::cout << "enter 10 integer values:" << endl;
    print_array(iArray);

    //for (int i=0; i < 10; i++){
        //cin >> intVal;
        //intVal = iArray[i];
    for (const auto& intVal : iArray){
        intTree.insertNode(intVal);
    }
    cout << endl;

    std::cout << endl << "Preorder traversal" << endl;
    intTree.preOrderTraversal();

    std::cout << endl << "Inorder traversal" << endl;
    intTree.inOrderTraversal();

    std::cout << endl << "Postorder traversal" << endl;
    intTree.postOrderTraversal();

    Tree<float> floatTree;
    float floatVal;
    float fArray[] {39.2, 16.5, 82.7, 3.3, 3.3, 65.2, 90.8, 1.1, 4.4, 89.5, 92.5, 45.3, 82.7, 3.6};

    std::cout << endl << endl << endl << "Enter 10 float values: "
        << endl << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(1);
    print_array(fArray);

    //for (int i = 0; i < 10; i++){
        //cin >> floatVal;
        //floatVal = fArray[i];
    for (const auto& floatVal : fArray){
        floatTree.insertNode(floatVal);
    }

    std::cout << endl << "Preorder traversal" << endl;
    floatTree.preOrderTraversal();

    std::cout << endl << "Inorder traversal" << endl;
    floatTree.inOrderTraversal();

    std::cout << endl << "Postorder traversal" << endl;
    floatTree.postOrderTraversal();
    
    std::cout << endl; 


}