#include <concepts>
#include <iostream>
#include <string>

// C++20: Constraints for Member Functions

template <typename T>
class MyType {
    T value;

public:
    // ...
    void print() const {
        std::cout << value << '\n';
    }

    bool isZero() const
        requires std::integral<T> || std::floating_point<T>
    {
        return value == 0;
    }

    bool isEmpty() const
        requires requires { value.empty(); }
    {
        return value.empty();
    }
};

int main() {
    MyType<double> mt1;
    mt1.print(); // OK
    if (mt1.isZero()) {
        // ...
    } // OK
    if (mt1.isEmpty()) {
        // ...
    } // ERROR

    MyType<std::string> mt2;
    mt2.print(); // OK
    if (mt2.isZero()) {
        // ...
    } // ERROR
    if (mt2.isEmpty()) {
        // ...
    } // OK
}
