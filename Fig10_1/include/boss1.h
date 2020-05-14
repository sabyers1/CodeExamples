// boss1.h
// Boss class derived from Employee
#ifndef BOSS1_H
#define BOSS1_H
#include "employ2.h"

class Boss: public Employee {
    public:
        Boss (const char *, const char *, float = 0.0);
        void setWeeklySalary(float);
        virtual float earnings() const;
        virtual void print() const;
    private:
        float weeklySalary;
};

#endif