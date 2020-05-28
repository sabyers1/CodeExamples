#include <iostream>
using namespace std;

struct X {
    int m;
};

int main (){

    auto_ptr<X> p (new(X));
    p->m = 6; 
    auto_ptr<X> q (p);  // q assumes p's point and sets p to null

    cout << "p ptr is: " << p.get() 
        << " q value is: " << q->m << endl;

    return 0;
}