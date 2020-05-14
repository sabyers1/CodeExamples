// Boss1.cpp
// Member function definitions for class Boss
#include <iostream>

using namespace std;

#include "boss1.h"

// Constructor function for class Boss
Boss::Boss(const char *first, const char *last, float s)
    : Employee(first, last)     // call base-class constructor
    {
        setWeeklySalary(s);
    }

// Set the Boss's salary
void Boss::setWeeklySalary(float s)
{
    weeklySalary = s > 0 ? s : 0;
}

// Get the Boss's salary
float Boss::earnings() const {return weeklySalary;}

// Print the Boss's name
void Boss::print() const
{
    cout << endl << "            Boss: " << getFirstName()
        << ' ' << getLastName();
} 