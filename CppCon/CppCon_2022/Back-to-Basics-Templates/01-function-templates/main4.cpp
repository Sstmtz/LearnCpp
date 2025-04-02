#include <iostream>
#include <list>
#include <vector>

// C++20: auto Parameters for Ordinary Functions

// use template:
// template <typename T>
// void printColl(T const &coll) {
//     for (auto const &elem : coll) {
//         std::cout << elem << '\n';
//     }
// }

// use auto:
// 1. Generic code
// 2. Usually in header files
// 3. No inline
void printColl(auto const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector<int>  v;
    std::list<double> l;
    printColl(v);
    printColl(l);
    printColl("Hello");
}
