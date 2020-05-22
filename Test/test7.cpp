#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>
#include <math.h>

std::pair<double, double> findRoots(double a, double b, double c)
{
 
   std::pair<double,double> roots;
   double determinant = (b*b)-(4*a*c);
   if (determinant == 0){
       roots.first = roots.second = -b/(2*a);
       return roots;
   } else if (determinant > 0){
       roots.first = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
       roots.second = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
       return roots;
   } else {
 //      roots.first = (-b+sqrt((b*b)-(4*a*c)))/(2*a);
 //      roots.second = (-b-sqrt((b*b)-(4*a*c)))/(2*a);
       throw std::logic_error("Imaginary roots");

       return roots;
   }
 
}

#ifndef RunTests
int main()
{
    std::pair<double,double> roots = findRoots(2, 10, 8);
    std::cout << "Roots: " + std::to_string(roots.first) + ", " + std::to_string(roots.second)<<std::endl;
    return 0;
}
#endif