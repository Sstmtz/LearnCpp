
// [[nodiscard]] and Functions
//
// Instructs the compiler to generate a warning if a return value is dropped.
// Can be applied to types or function declarations.

[[nodiscard]] int get_value();

int main() {
    get_value(); // warning issued from any reasonable compiler

    // C++23 fixes a minor loophole in the standard and now allows
    // [[nodiscard]] with lambdas.

    auto l = [] [[nodiscard]] () -> int {
        return 42;
    }; // warning here
}
