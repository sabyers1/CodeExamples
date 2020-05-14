/*
 * File: fig11_08.cpp
 * File Create: 25th April 2020
 * Author: H.M. Deitel
 * -----
 *  Printing the address of stored in char* variable
 *  
 * -----
 * Last Modified: 25th April 2020 5:10:13 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */

#include <iostream>
using namespace std;

int main()
{
    const char *string = "test";
    cout << "Value of string is: " << string << endl
        << "Value of (void *)string is: "
        << (void *)string << endl;

    // int x, y;
    
    // cout << "Enter two integers: ";
    // cin >> x >> y;
    // cout << "Sum of " << x << " and " << y << " is: "
    //     << (x + y) << endl;

    int grade, highestGrade = -1;
    cout << "Enter grade (enter Ctrl-D to end): ";
    while (cin>>grade){
        if (grade > highestGrade)
            highestGrade = grade;

        cout << "Enter grade (enter Ctrl-D for EOF or ^Z to end): ";
    }

    cout << endl << "Highest grade is: " << highestGrade << endl;
    
    return 0;
}
