
// Half-Open Range (C++11)
//
// Iterate like a pointer over a collection
// - begin() and end() as half-open range

#include <iostream>
#include <vector>

int main() {
    int arr[] = {10, 20, 30, 40};

    for (int *p = arr; p < arr + 4; ++p) {
        std::cout << *p << '\n';
    }

    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    for (auto pos = v.begin(); pos < v.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    // auto pos = v.end() // OK
    // std::cout << *pos; // UB

    std::vector<int> v2; // empty

    for (auto pos = v2.begin(); pos < v2.end(); ++pos) {
        std::cout << *pos << '\n';
    }
}
