/*
 * Filename: /Users/sabyers1/Documents/src/CPP/Fig10_1/src/piece1.cpp
 * Path: /Users/sabyers1/Documents/src/CPP/Fig10_1/src
 * Created Date: Saturday, April 25th 2020, 2:24:12 pm
 * Author: Stephen Byers
 *
 * Member function definitions for class PieceWorker
 *  
 */
#include <iostream>
using namespace std;
#include "piece1.h"

// Constructor for class PieceWorker
PieceWorker::PieceWorker(const char *first, const char *last, float w, unsigned q)
    : Employee(first, last)     // call base-class constructor
    {
        wagePerPiece = w > 0 ? w: 0;
        quantity = q > 0 ? q : 0;
    }
    
// Set the wage
void PieceWorker::setWage(float w) { wagePerPiece = w > 0 ? w: 0; }

// Set the number of items output
void PieceWorker::setQuantity(unsigned q) { quantity = q > 0 ? q: 0; }

// Determine the PieceWorker's earnings
float PieceWorker::earnings() const { return quantity * wagePerPiece; }

// Print the PieceWorker's name
void PieceWorker::print() const{
    cout << endl << "     Piece worker: " << getFirstName()
        << ' ' << getLastName();
}