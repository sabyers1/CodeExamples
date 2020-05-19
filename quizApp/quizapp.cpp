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

// A quiz consists of a variable number of questions.
// A question includes A. The question B. Choices for answers C. Answer D. Score
// The quiz has a student and their respective score.
// A quiz can allow single or multiple attempts.
// Attempts can lower the score or have not impact.



int main(){
   //demoQuizSave();

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
    cout << "OK " << studentName << " I hope you are ready for your quiz!"<<endl;

    TiXmlNode* node = 0;
    node = doc.RootElement();
    
    cout << "Debug, node: "<< node <<endl;

    //TiXmlElement* ChoiceElement = 0;
    //TiXmlElement* AnswerElement = 0;
    TiXmlHandle docHandle(node);
    TiXmlElement*  qElement = docHandle.FirstChild("Question").FirstChild("Choice").ToElement();
    
    TiXmlElement *root = doc.FirstChildElement("Quiz");
    if(root){
        TiXmlElement *element = root->FirstChildElement("Question");
        if(element){
            TiXmlElement *qText = element->FirstChildElement("QText");
            if(qText){
                cout << "Debug, qText: "<< qText->GetText()<<endl;
            }
        }
    }


    cout << "Debug, Element: "<< qElement << " Handle: " << docHandle.Text() << endl;

    // Loop through the questions and collect answers
   // bool moreQuestions = true;
    int curQuestion=1;
   // while (moreQuestions){
        // Present question and wait for answer
        for(;qElement;qElement=qElement->NextSiblingElement()){
            cout << "Q" << curQuestion <<": "<< qElement->GetText()<< endl <<endl;
            curQuestion++;
      //      moreQuestions = false;
        }
    //}
    return 0;
}