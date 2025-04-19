// C++14: Generic Lambdas

// - Lambdas for generic parameter types
//   - Using `auto`
//   - Defines function template member
//     - Using template deduction rules apply

#include <iostream>
#include <string>
auto plus = [](auto x, auto y) {
    return x + y;
};

// has the effect of:
//
// class lambda??? {
// public:
//     lambda??? (); // only callable by compiler before C++20
//     template<typename T1, typename T2>
//     auto operator()(T1 x, T2 y) const {
//         return x + y;
//     }
// }
//
// auto plus = lambda???{};

int main() {
    int i = 42;
    double d = plus(7.7, i); // calls plus.operator()<double, int>(7.7, i);
    std::string s {"hi"};
    std::cout << plus("s: ", s) << '\n';
}
