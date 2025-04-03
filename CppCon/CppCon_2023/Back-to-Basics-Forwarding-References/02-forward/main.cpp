
// Passing temporary arguments

// void foo(int const &x) {
//     int tmp = x;
//     x = 0; // ERROR
// }
//
// lvalue references to const CAN'T be mutated
// True even if we pass a temporary (rvalue)

void foo(int &x) {
    int tmp = x;
    x = 0; // OK
}

// rvalue references CAN be mutated
// Enable Move Semantics

int main() {
    return 0;
}
