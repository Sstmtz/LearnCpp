#include <functional>
#include <iostream>
#include <memory>
#include <print>

int Process(std::function<int()> f) {
    return f() * 2;
}

// C++23:
int Process_(std::move_only_function<int()> f) {
    return f() * 2;
}

int main() {
    // This can be called as follows:
    std::print("{}", Process([] {
                   return 21;
               })); // 42
    // But this failed:
    // std::cout << Process([p = std::make_unique<int>(42)] {
    //     return *p;
    // });
    // "Attemping to reference a deleted function"
    // - The copy ctor of the std::function tries to copy the lambda,
    //   which is not possible due to the captures unique_ptr

    // This can be called as follows:
    std::print("{}", Process_([] {
                   return 21;
               })); // 42
    std::cout << Process_([p = std::make_unique<int>(42)] {
        return *p;
    }); // 84
}
