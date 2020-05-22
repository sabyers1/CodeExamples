#include <iostream>
#include <string>

class TextInput
{
public:
    virtual void add(char c) { this->val += c;}

    std::string getValue() { return this->val; }

private:
    std::string val;
};
class NumericInput : public TextInput 
{ 
public:
     void add(char c) {
         if(isdigit(c)){
            TextInput::add(c);
         }
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue()<<std::endl;

    NumericInput* p = new NumericInput();
    p->add('1');
    p->add('a');
    p->add('0');
    std::cout << p->getValue()<<std::endl;

}
#endif