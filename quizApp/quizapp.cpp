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

const char *demoQuiz =
    "<Quiz>\n"
        "<AllowedAttempts>1</AllowedAttempts>\n"
        "<ScoreLowered>0.30</ScoreLowered>\n"
        "<StudentName></StudentName>\n"
        "<Question>\n"
            "<QText>Where is called the 'Rooftop of the world'?</QText>\n"
            "<Choice item=1>Tibet</Choice>\n"
            "<Choice item=2>Sears Tower</Choice>\n"
            "<Choice item=3>Mt. McKinley</Choice>\n"
            "<Choice item=4>Nepal</Choice>\n"
            "<Answer>1</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
        "<Question>\n"
            "<QText>Where is the 'Holy Land'?</QText>\n"
            "<Choice item=1>Jerusalem</Choice>\n"
            "<Choice item=2>Mathura</Choice>\n"
            "<Choice item=3>Mecca</Choice>\n"
            "<Choice item=4>Newark</Choice>\n"
            "<Answer>1</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>Where is called 'The land of the rising sun'?</QText>\n"
            "<Choice item=1>Chicago</Choice>\n"
            "<Choice item=2>Japan</Choice>\n"
            "<Choice item=3>Tibet</Choice>\n"
            "<Choice item=4>Puerto Rico</Choice>\n"
            "<Answer>2</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
                "<Question>\n"
            "<QText>What is called 'The gift of the Nile'?</QText>\n"
            "<Choice item=1>Chicago</Choice>\n"
            "<Choice item=2>Egypt</Choice>\n"
            "<Choice item=3>Africa</Choice>\n"
            "<Choice item=4>Alexandria</Choice>\n"
            "<Answer>2</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
                "<Question>\n"
            "<QText>Where is the 'Land of Midnight'?</QText>\n"
            "<Choice item=1>Norway</Choice>\n"
            "<Choice item=2>Japan</Choice>\n"
            "<Choice item=3>Australia</Choice>\n"
            "<Choice item=4>Antartica</Choice>\n"
            "<Answer>1</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>What is called 'The land of Thunderbolt?</QText>\n"
            "<Choice item=1>Wyomming</Choice>\n"
            "<Choice item=2>Canada</Choice>\n"
            "<Choice item=3>Arabia</Choice>\n"
            "<Choice item=4>Bhutan</Choice>\n"
            "<Answer>4</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>Where is the 'Windy City'?</QText>\n"
            "<Choice item=1>Tokoyo</Choice>\n"
            "<Choice item=2>Taipai</Choice>\n"
            "<Choice item=3>Chicago</Choice>\n"
            "<Choice item=4>St Johns</Choice>\n"
            "<Answer>3</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>Where is the 'Land of White Elephants'?</QText>\n"
            "<Choice item=1>Bangladesh</Choice>\n"
            "<Choice item=2>Thailand</Choice>\n"
            "<Choice item=3>India</Choice>\n"
            "<Choice item=4>South Africa</Choice>\n"
            "<Answer>2</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>Where is the 'City of Seven Hills'?</QText>\n"
            "<Choice item=1>Rome</Choice>\n"
            "<Choice item=2>Nilgiri Hills</Choice>\n"
            "<Choice item=3>Tibet</Choice>\n"
            "<Choice item=4>Pittsburgh</Choice>\n"
            "<Answer>3</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
         "<Question>\n"
            "<QText>What is called 'The Dark Contenient'?</QText>\n"
            "<Choice item=1>Asia</Choice>\n"
            "<Choice item=2>Australia</Choice>\n"
            "<Choice item=3>Africa</Choice>\n"
            "<Choice item=4>South America</Choice>\n"
            "<Answer>3</Answer>\n"
            "<Score>10</Score>\n"
        "</Question>\n"
    "</Quiz>";

// Quick way to make demo file if needed
void demoQuizSave(){
    TiXmlDocument doc("quizinfo.xml");
    doc.Parse(demoQuiz);
    if (doc.Error()){
        cout << "Error in "<< doc.Value() <<": "<< doc.ErrorDesc()<< endl;
        exit(1);
    }
    doc.SaveFile();
}

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