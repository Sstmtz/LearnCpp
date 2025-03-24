#include <utility> // for std::unreachable()

// Marking code as unreachable can improve performance
// E.g:
void do_something(int number_that_is_only_0_1_2_or_3) {
    switch (number_that_is_only_0_1_2_or_3) {
        case 0:
        case 2 : handle_0_or_2(); break;
        case 1 : handle_1(); break;
        case 3 : handle_3(); break;
        default: std::unreachable();
    }
}

// Compilers can then skip generating code to verify that
// the value is between 0 and 3
