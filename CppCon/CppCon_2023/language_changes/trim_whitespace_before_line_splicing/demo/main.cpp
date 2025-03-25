#include <iostream>

int main() {
    int i = 1
        // \
    + 42
        ;
    std::cout << i;
    // before C++23:
    // GCC and Clnag writes 1
    // MSVC writes 43
    // since C++23:
    // C++23 mandates that whitespace after a \ line continuation
    // character is stripped, so result should be 1
}
