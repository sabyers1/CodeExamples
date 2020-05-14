// COMMIS1.CPP
// Member function definitions for class CommissionWorker
#include <iostream>

using namespace std;

#include "commis1.h"

// Constructor for class COmmissionWorker
CommissionWorker::CommissionWorker(const char *first,
        const char *last, float s, float c, unsigned q)
        : Employee(first, last)     // call base-class constructor
{
    salary = s > 0 ? s : 0;
    commission = c > 0 ? c : 0;
    quantity = q > 0 ? q : 0;
}

// Set CommissionWorker's weekly base salary
void CommissionWorker::setSalary(float s)
{ salary = s > 0 ? s : 0; }

// Set CommissionWorker's commission
void CommissionWorker::setCommission(float c)
    { commission = c > 0 ? c : 0; }

// Set CommissionWorker's quantity sold
void CommissionWorker::setQuantity(unsigned q)
    {    quantity = q > 0 ? q : 0;}

// Set CommissionWorker's earnings
float CommissionWorker::earnings() const
    { return salary + commission * quantity; }

// Print the CommissionWorkers name
void CommissionWorker::print() const
{
    cout << endl << "Commission worker: " << getFirstName()
        << ' ' << getLastName();
} 