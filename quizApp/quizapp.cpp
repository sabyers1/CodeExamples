/*
 * File: quizapp.cpp
 * File Create: 18th May 2020
 * Author: Stephen Byers
 * -----
 *  Application to quiz user and provide a score from an XML file source.
 *  Uses TinyXML parser
 *  
 * -----
 * Last Modified: 18th May 2020 2:43:29 pm
 * Modified By: Stephen Byers
 * -----
 * No Copyright 2020
 */

#include <iostream>
#include <sstream>
using namespace std;

#include "tinyxml.h"

#include <istream>
#include <limits>

/*  Template written by Roger Pate, 09jan10 
    to clear std input if alpha char submitted instead of integer
    Can be called as clearline(stream) or stream >> clearline
 */
template<class C, class T>
std::basic_istream<C,T>& clearline(std::basic_istream<C,T>& s) {
  s.clear();
  s.ignore(std::numeric_limits<std::streamsize>::max(), s.widen('\n'));
  return s;
}

void AnnounceScore(string n, double s, double p);

// A quiz consists of a variable number of questions.
// A question includes A. The question B. Choices for answers C. Answer D. Score
// The quiz has a student and their respective score.
// A quiz can allow single or multiple attempts.
// Attempts can lower the score or have not impact.

int main(){

    // Open file with quiz content and parse
    TiXmlDocument doc("quizinfo.xml");
    
    bool loadOkay = doc.LoadFile();
    if (!loadOkay){
        cout << "Could not load file: "<< doc.Value() <<" Error: "<< doc.ErrorDesc()<< endl;
        exit(1);
    }
    //doc.Print(stdout);

    // Get the student's name
    string studentName;
    while( studentName.size() < 1 ){
        cout << "Please enter your full name:";
        getline(cin,studentName);
    }
    cout << "\nOK " << studentName << " I hope you are ready for your quiz!"<<endl<<endl;
    
    TiXmlNode* node = 0;
    node = doc.RootElement();
    TiXmlHandle docHandle(node);
    TiXmlElement *gElement;

    TiXmlElement*  qElement = docHandle.FirstChild("Question").ToElement();
    
    double totalScore = 0.0;
    double totalPossible = 0.0;
    int allowedAttempts = stoi(docHandle.FirstChild("AllowedAttempts").ToElement()->GetText());
    if (allowedAttempts <= 0) allowedAttempts = 1;
    double scoreDeflation = stod(docHandle.FirstChild("ScoreLowered").ToElement()->GetText());
    if (0.0 > scoreDeflation || scoreDeflation > 1.0) scoreDeflation = 1.0;

    // Loop through the questions and collect answers
    // Present question and wait for answer
    for(int curQ=1; qElement; qElement=qElement->NextSiblingElement("Question"),curQ++){
        cout << "---------------"<< endl;
        cout << "Q" << curQ <<": "<< qElement->FirstChildElement("QText")->GetText()<< endl;

        // Loop through the choices
        TiXmlElement *cElement=qElement->FirstChildElement("Choice");
        int curC = 1;
        for(;cElement; cElement=cElement->NextSiblingElement("Choice"),curC++){
                cout << "    C" << curC <<": "<< cElement->GetText() << endl;
            }
        int answer = 0;
        double qScore = stod(qElement->FirstChildElement("Score")->GetText());
        if (qScore < 0) qScore = 1;
        totalPossible += qScore;

        int correctAnswer = atoi(qElement->FirstChildElement("Answer")->GetText());

        for(int trys=0;trys < allowedAttempts;trys++){
            do{
                cout << "Please enter number of choice ( i.e. 1, 2, or 3): ";
                cin >> answer;
                if (cin.fail() || !(answer>0 && answer<curC)){
                    cout << "\nSorry '" << answer << "' is not a valid choice." << endl;
                    answer = 0;
                    clearline(cin);
                }
            }while(!(answer>0 && answer<curC));

            if (answer == correctAnswer){
                double dF = 1.0-((double)trys*scoreDeflation);
                if (dF<0.0) dF = 0.0;
                totalScore += (qScore * dF);
                trys = allowedAttempts;  // exit for loop
            } else if (trys < allowedAttempts-1){
                cout << "Incorrect. Please try again."<<endl;
            }
        }
    }

    AnnounceScore(studentName,totalScore,totalPossible);
    return 0;
}

void AnnounceScore(string studentName,double totalScore, double totalPossible){
    if (totalPossible < 0) totalPossible = 1;
    if (totalScore > totalPossible) totalScore = totalPossible;  
    double percent = totalScore/totalPossible;
    string comment="Probably need some more studying ";
    if (percent == 1.0) comment="Perfect ";
    else if (percent > 0.85) comment="Well done ";
    else if (percent > 0.70) comment="Good work ";
    
    cout << endl << comment << studentName << "! You scored: "<< totalScore
        << " out of " << totalPossible << " possible." << endl;
}