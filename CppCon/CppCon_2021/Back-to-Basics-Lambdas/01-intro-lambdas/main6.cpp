// Lambdas Without Captures

// - Lambdas with no captures
//   - Can be used as ordinary function pointers
//   - Can be used as sorting cirterion / hash function type (since C++20)

#include <cstdlib> // for atexit()
#include <iostream>
#include <unordered_set>

int main() {
    std::atexit([]() { // lambda to be called on regular exit
        std::cout << "good bye\n";
    });

    // auto hashFunc = [](auto const &obj) { // lambda to be used as hash function
    //     return ...;
    // };

    // std::unordered_set<MyType, decltype(hashFunc)> coll;
}
