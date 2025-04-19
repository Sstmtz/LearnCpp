// C++20: Universal/forwarding References for Ranges and Views

// - const views might not support iterating
//   - They might have to modify their state while iterating
//   - Use universal/forwarding references when passed by reference

#include <iostream>
#include <list>
#include <ranges>
#include <vector>

template <typename T>
void print(T const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

template <typename T>
void printElems(T &&coll) {
    // void printElems(auto &&coll) {
    for (auto const &elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector vec {1, 2, 3, 4, 5};
    print(vec);                       // OK
    print(vec | std::views::drop(3)); // OK
    // print(vec | std::views::filter(...)); // ERROR, without universal reference
    // printElems(vec | std::views::filter(...)); // OK

    std::list lst {1, 2, 3, 4, 5};
    // print(lst | std::views::drop(2)); // ERROR, without universal reference
    printElems(lst | std::views::drop(2)); // OK
}
