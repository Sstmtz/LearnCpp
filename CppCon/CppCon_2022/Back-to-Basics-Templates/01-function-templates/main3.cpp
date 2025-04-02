
// C++98: Templates In Header Files
//
// Templates are usually defined in header files
// - Not only declared
// - Not inline necessary

#include "main3.hpp"
#include <iostream>
#include <string>

int main() {
    int         i1 = 42, i2 = 77;
    std::string s {"hi"}, t {"world"};
    std::cout << mymax(i1, i2) << '\n';    // OK
    std::cout << mymax(0.7, 33.4) << '\n'; // OK
    std::cout << mymax(s, t) << '\n';      // OK
}
