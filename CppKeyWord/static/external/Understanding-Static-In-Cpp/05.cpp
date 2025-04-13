// Control linkage

#include <iostream>

// Consider this: Since global variables are stored in static memory, is the static keyword redundant here?
// In fact, this utilizes another feature of the static keyword: control linkage
static int count = 0;

void increment() {
    count++;
    std::cout << count << '\n';
}
