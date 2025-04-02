#include <iostream>
#include <set>
#include <string>
#include <vector>

// C++98: Function Templates
//
// Generic function code for arbitary types

template <typename T>
T mymax(T a, T b) {
    return b < a ? a : b;
}

int main() {
    int         i1 = 42, i2 = 77;
    std::string s {"hi"}, t {"world"};
    std::cout << mymax(i1, i2) << '\n';
    std::cout << mymax(0.7, 33.4) << '\n';
    std::cout << mymax(s, t);
}
