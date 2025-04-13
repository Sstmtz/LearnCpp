// Lifetime and Address

#include <iostream>

static int static_global;
int        non_static_global;

int main() {

    static int static_local;
    int        non_static_local;

    std::cout << "The static global lives at:     " << &static_global << '\n';     // in static memory
    std::cout << "The non-static global lives at: " << &non_static_global << '\n'; // in static memory
    std::cout << "The static local lives at:      " << &static_local << '\n';      // in static memory
    std::cout << "The non-static local lives at:  " << &non_static_local << '\n';  // in stack

    return 0;
}
