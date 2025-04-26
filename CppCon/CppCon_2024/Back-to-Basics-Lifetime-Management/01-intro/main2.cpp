#include <iostream>

// Special Member Functions
// 1. The compiler will generate special member functions (SMFs) for you
// 2. Defining some SMFs may delete or disable some others

// class Gadget {
// public:
//     int i;
// };
//
// struct Gadget {
//     int i;
// };
//
// int main() {
//     Gadget gadget;
//     std::cout << gadget.i << '\n'; // UB, take garbage value from memory
// }

// struct Gadget {
//     int i;
//
//     Gadget() : i(0) {} // default constructor
// };
//
// struct Gadget {
//     int i = 0; // default member initializer
// };
//
// int main() {
//     Gadget gadget;
//     std::cout << gadget.i << '\n'; // 0
// }

// struct Gadget {
//     int i;
//
//     Gadget(int i) : i(i) {} // custom constructor
// };
//
// int main() {
//     Gadget gadget(42);
//     std::cout << gadget.i << '\n'; // 42
//
//     Gadget gadget;                 // ERROR, because default constructor was disabled
// }

// struct Gadget {
//     int i = 0;              // default member initializer
//
//     Gadget(int i) : i(i) {} // custom constructor
// };
//
// int main() {
//     Gadget gadget(42);
//     std::cout << gadget.i << '\n'; // 42
//
//     Gadget gadget;                 // ERROR, because default constructor was disabled,
//     // and even reusing the default member initializer does not work
// }

struct Gadget {
    int i = 0;

    // Gadget() {}         // explicitly implemented default constructor

    Gadget() = default; // compiler generated default constructor

    Gadget(int i) : i(i) {}
};

int main() {
    Gadget gadget;                 // OK
    gadget = Gadget(42);
    std::cout << gadget.i << '\n'; // 42
}
