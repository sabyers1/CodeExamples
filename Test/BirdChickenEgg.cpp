#include <stdexcept>
#include <functional>
#include <iostream>
using namespace std;


/* 
 * Chicken implements Bird class
 * A chicken lays an egg that will hatch into a new Chicken
 * Eggs from other typs of birds should hatch into a new bird of their
 * parent type.
 * Hatching an egg for the second time throws logic error.
 */
  
 
class Egg;

class Bird
{ 
public:
    virtual ~Bird() {};     // virtual destructor for derived class
    virtual Egg* lay() = 0;  // = 0 makes pure virtual
};

class Egg
{
private:
    int m_eggCnt;  // instance counter to prevent multiple hatches
    std::function <Bird* () > m_createBird;  // pointer to function to create bird from egg.

public:
    Egg(std::function<Bird* ()> createBird)  // need to have function target so not bad call
    {
        m_eggCnt = 0;
        m_createBird = createBird; // redirect/assign to exterior class function
        cout << "Constructed egg." << endl;
    }

    Bird* hatch()
    {  // hatching creates bird of parent type
        cout << "Hatching " << (m_eggCnt==0?"first":"subsequent")<<" time"<< endl;
        if (++m_eggCnt>1)
            throw std::logic_error("Attempted to hatch egg too many times.");
        
        return m_createBird();
    }

};


Bird* createChicken();

class Chicken : public Bird
{ 
public:
    Chicken()
    {
        cout << "Constructing chicken." << endl;
    }

    Egg* lay()
    { // laying creates an egg
        cout << "Laying chicken egg." << endl;
        Egg *e = new Egg(::createChicken);
        return e;
    }
    
};

Bird* createGoose();

class Goose: public Bird
{
public:
    Goose(){
        cout << "Constructing goose." << endl;
    }

    Egg* lay()
    { // laying creates an egg
        cout << "Laying goose egg." << endl;
        return new Egg(::createGoose);
    }
};

Bird *createChicken(){
    cout << "::createChicken()"<< endl;
    return new Chicken();
}

Bird *createGoose(){
    cout << "::createGoose()"<< endl;
    return new Goose();
}


#ifndef RunTests
int main()
{
    Bird* chicken = new Chicken();
    Bird* goose = new Goose();

    Egg* egg1 = chicken->lay();
    Bird* childChicken1 = egg1->hatch();

    try{
        Bird* childChicken2 = egg1->hatch();
    } catch (std::logic_error e){
        cout << "Expected error: " << e.what() << endl;
    } catch (exception e){
        cout << "Unexpected error: " << e.what() << endl;
    }

    Egg* egg2 = chicken->lay();
    Bird *childChicken3 = egg2->hatch();

    Egg* egg3 = goose->lay();
    Bird* childGoose = egg3->hatch();

    cout << "All done!" << endl;

    return 0;
}
#endif