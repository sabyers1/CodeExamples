/*
 * File: hourly1.h
 * File Create: 25th April 2020
 * Author: H.M. Deitel
 * -----
 * Last Modified: 25th April 2020 3:03:06 pm
 * Modified By: Stephen Byers
 * -----
 * 
 * Definition of class HourlyWorker
 * 
 * No Copyright 2020
 */
#ifndef HOURLY1_H
#define HOURLY1_H
#include "employ2.h"

class HourlyWorker: public Employee
{
private:
    float wage;     // wage per hour
    float hours;    // hours worked for week
public:
    HourlyWorker(const char*, const char*, float = 0.0, float = 0.0);
    void setWage(float);
    void setHours(float);
    virtual float earnings() const;
    virtual void print() const;
};
#endif