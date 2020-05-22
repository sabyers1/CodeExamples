#include <stdexcept>
#include <functional>


/* Chicken implements Bird class
 * A chicken lays an egg that will hatch into a new Chicken
 * Eggs from other typs of birds should hatch into a new bird of their
 * parent type.
 * Hatching an egg for the second time throws logic error.
 */
  
 
class Egg;

class Bird
{
public:
    virtual ~Bird() {};
    virtual Egg* lay() = 0;  // 0 makes virtual
};

class Egg
{
public:
    Egg(std::function<Bird* ()> createBird)
    {
        throw std::logic_error("Waiting to be implemented");
    }

    Bird* hatch()
    {
         if (eggCnt>=2)
            throw std::logic_error("Too many eggs hatched by Chicken.");
    }
};

class Chicken : public Bird
{

public:
    Chicken()
    {
    }

    Egg* lay()
    {
        
    }
    ~Bird() { 
        delete Bird::Egg;
    }
    
};

#ifndef RunTests
int main()
{
    Bird* chicken = new Chicken();

    Egg* egg1 = chicken->lay();
    Bird* childChicken1 = egg1->hatch();
}
#endif