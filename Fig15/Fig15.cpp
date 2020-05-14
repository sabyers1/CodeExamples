/*
 * File: Fig15.cpp
 * File Create: 30th April 2020
 * Author: H.M. Deitel
 * -----
 *  Chapter 15 example of linked list datastructure and use of templates
 *  
 * -----
 * Last Modified: 30th April 2020 11:45:08 am
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */

#include <iostream>
#include "list.h"

void testIntegerList();
void testFloatList();
void instructions();

int main(){

    testIntegerList();
    testFloatList();

    return 0;
}

// Method to test an integer list
void testIntegerList(){
    cout << "Testing a List of integer values" << endl;

    xList<int> integerList;
    instructions();

    int choice, value;

    do {
        cout << "? ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter an integer: ";
                cin >> value;
                integerList.insertAtFront(value);
                integerList.print();
                break; 
            case 2:
                cout << "Enter an integer: ";
                cin >> value;
                integerList.insertAtBack(value);
                integerList.print();
                break; 
            case 3:
                if (integerList.removeFromFront(value))
                    cout << value << " removed from list" << endl;
                integerList.print();
                break;
            case 4:
                if (integerList.removeFromBack(value))
                    cout << value << " removed from list" << endl;
                integerList.print();
                break;
        }
    } while (choice != 5);
    cout << "End test of integer List" << endl;
}

// Method to test an Float list
void testFloatList(){
    cout << "Testing a List of float values" << endl;

    xList<float> floatList;
    instructions();

    int choice;
    float value;

    do {
        cout << "? ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter a floating point number: ";
                cin >> value;
                floatList.insertAtFront(value);
                floatList.print();
                break; 
            case 2:
                cout << "Enter a floating point number: ";
                cin >> value;
                floatList.insertAtBack(value);
                floatList.print();
                break; 
            case 3:
                if (floatList.removeFromFront(value))
                    cout << value << " removed from list" << endl;
                floatList.print();
                break;
            case 4:
                if (floatList.removeFromBack(value))
                    cout << value << " removed from list" << endl;
                floatList.print();
                break;
        }
    } while (choice != 5);
    cout << "End test of float List" << endl;
}

void instructions ()
{
    cout << "Enter one of the following: " << endl
        << "  1 to insert at the beginning of list" << endl
        << "  2 to insert at the end of the list" << endl
        << "  3 to delete from the beginning of the list" << endl
        << "  4 to delete from the end of the list" << endl
        << "  5 to end list processing" << endl;
}