#include <iostream>

// int very_important_number = 100; // duplicate symbol error

static int very_important_number = 10; // OK, internal linkage

// extern int very_important_number; // OK

int exceedingly_crucial_calculation() {
    return very_important_number;
}
