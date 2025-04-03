
// Iterating with Generic Code
//
// Iterator API provided by all containers:
// - begin() and end() yield iterators
//  - to iterator over elements with ++, !=, *, ...
// - Use by the range-based for loop

#include <iostream>
#include <set>
#include <string>
#include <vector>

// template <typename T>
// void printElems(T const &coll) {
//
//     for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
//         std::cout << *pos << '\n';
//     }
// }

// C++11:
// template <typename T>
// void printElems(T const &coll) {
//
//     for (auto const &elem : coll) {
//         std::cout << elem << '\n';
//     }
// }

// C++20:
void printElems(auto const &coll) {

    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector<int> coll1;
    printElems(coll1);
    // compiles:
    // void printElems(std::vector<int> const &coll) {
    //     // ++ just moves n bytes to the next element
    // }

    std::set<std::string> coll2;
    printElems(coll2);
    // compiles:
    // void printElems(std::set<std::string> const &coll) {
    //     // ++ navigates to the next element
    // }
}
