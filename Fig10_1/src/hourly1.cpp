/*
 * File: hourly1.cpp
 * File Create: 25th April 2020
 * Author: H.M. Deitel
 * -----
 * Last Modified: 25th April 2020 3:10:10 pm
 * Modified By: Stephen Byers
 * -----
 * 
 * Member function definitions for classs HourlyWorker
 * No Copyright 2020
 */
#include <iostream>
using namespace std;
#include "hourly1.h"

// Constructor for class HourlyWorker
HourlyWorker::HourlyWorker(const char *first, const char *last, float w, float h)
    : Employee(first, last)
    {
        wage = w > 0 ? w : 0;
        hours = h >= 0 && h < 168 ? h : 0;
    }

// Set the wage
void HourlyWorker::setWage(float w) { wage = w > 0 ? w: 0; }

// Set the hours worked
void HourlyWorker::setHours(float h) { hours = h >= 0 && h < 168 ? h : 0; }

// Determine the HourlyWorker's pay
float HourlyWorker::earnings() const { return wage * hours; }

// Print the HourlyWorker's name
void HourlyWorker::print() const{
    cout << endl << "  Hourly worker: " << getFirstName()
        << ' ' << getLastName();
}
