// FIG10_1.CPP
// Driver for Employee hierarchy
#include <iostream>
#include <iomanip>
using namespace std;
#include "employ2.h"
#include "boss1.h"
#include "commis1.h"
#include "piece1.h"
#include "hourly1.h"

int main()
{
    // set ouptput formatting to be floating-point with 2 decimal values
    cout << setiosflags(ios::showpoint) << fixed << setprecision(2);

    Employee *ptr;      // base-class pointer

    Boss b("John", "Smith", 800.00);
    ptr = &b;       // base-class pointer to derived-class object
    ptr->print();   // dynamic binding
    cout << " earned $" << ptr->earnings(); // dynamic binding
    b.print();      // static binding
    cout << " earned $" << b.earnings(); // dynamic binding

    CommissionWorker c("Sue", "Jones", 200.0, 3.0, 150);
    ptr = &c;
    ptr->print();
    cout << " earned $" << ptr->earnings();
    c.print();
    cout << " earned $" << c.earnings();

    PieceWorker p("Bob", "Lewis", 2.5, 200);
    ptr = &p;
    ptr->print();
    cout << " earned $" << ptr->earnings();
    p.print();
    cout << " earned $" << p.earnings();

    HourlyWorker h("Karen", "Price", 13.75, 40);
    ptr = &h;
    ptr->print();
    cout << " earned $" << ptr->earnings();
    h.print();
    cout << " earned $" << h.earnings();


    cout << endl;
    return 0;
}