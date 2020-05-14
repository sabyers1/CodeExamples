#include <iostream>
#include <vector>

int bind_example();

int main() {
  std::vector<int> v1(1, 2);
  std::vector<int> v2{ 1, 2 };
  std::cout << v1.size() << v2.size() << std::endl;
  std::cout << "V1: " << v1[0]<< " " << v1[1] << std::endl;
  std::cout << "V2: " << v2[0]<< " " << v2[1] << std::endl;
  std::cout << "V1: " << *(v1.begin()) << " " << *(v1.end()) << std::endl;
  std::cout << "V2: " << *(v2.begin()) << " " << *(v2.end()) << std::endl;

  for (int x : v1)
    std::cout << x << ",";
  std::cout << std::endl;

    bind_example();
}

// cplusplus example of bind capabilities.

double my_divide (double x, double y) {return y!=0 ? x/y : 0;}

struct MyPair {
    double a, b;
    double multiple() {return a*b;}
};

int bind_example(){
    using namespace std::placeholders;  // adds visibilities of _1, _2, _3...

    //binding functions
    auto fn_five = std::bind (my_divide, 10, 2);
    std::cout << fn_five() << std::endl;

    auto fn_half = std::bind (my_divide,_1,2);
    std::cout << fn_half(8) << std::endl;                    // 4

    auto fn_invert = std::bind (my_divide,_2,_1);            // returns y/x
    std::cout << fn_invert(10,2) << '\n';                    // 0.2
    
    auto fn_rounding = std::bind<int> (my_divide,_1,_2);     // returns int(x/y)
    std::cout << fn_rounding(10,3) << '\n';                  // 3

    
    MyPair ten_two {10, 2};

    auto bound_member_fn = std::bind (&MyPair::multiple,_1);
    std::cout << bound_member_fn(ten_two) << std::endl;

    auto bound_member_data = std::bind (&MyPair::a,ten_two); // returns ten_two.a
    std::cout << bound_member_data() << '\n';                // 10

    return 0;
}