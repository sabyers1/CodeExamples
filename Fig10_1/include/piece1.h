/*
 * Filename: /Users/sabyers1/Documents/src/CPP/Fig10_1/include/piece1.h
 * Path: /Users/sabyers1/Documents/src/CPP/Fig10_1/include
 * Created Date: Saturday, April 25th 2020, 2:08:36 pm
 * Author: Stephen Byers
 * 
 * PeiceWorker Class derived from Employee
 */
#ifndef PIECE1_H
#define PIECE1_H
#include "employ2.h"

class PieceWorker : public Employee {
    public:
        PieceWorker(const char*, const char*, float = 0.0, unsigned = 0);
        void setWage(float);
        void setQuantity(unsigned);
        virtual float earnings() const;
        virtual void print() const;
    private:
        float wagePerPiece;     // wage for each piece output
        unsigned quantity;      // output for week
};

#endif
