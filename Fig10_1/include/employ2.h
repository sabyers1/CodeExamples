// employ2.h
// Abstract base class Employee
#ifndef EMPLOY2_H
#define EMPLOY2_H

class Employee {
    public:
        Employee(const char *, const char *);
        ~Employee();
        const char *getFirstName() const;
        const char *getLastName() const;

        //Pure virtual functions make Employee abstract base class.
        virtual float earnings() const = 0;     // pure virtual
        virtual void print() const = 0;         // pure virtual
    private:
        char *firstName;
        char *lastName;

};

#endif
