
// Iterators: Generalization of Pointers that Iterate (C++98/C++11)
//
// Iterate like a pointer over elements
// - From begin() til end()

#include <iostream>
#include <string>
#include <vector>

int main() {

    int arr[] = {10, 20, 30, 40};

    for (int *p = arr; p < arr + 4; ++p) {
        std::cout << *p << '\n';
    }

    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    for (std::vector<int>::iterator pos = v.begin(); pos < v.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    // C++11:
    // for (auto pos = v.begin(); pos < v.end(); ++pos) {
    //     std::cout << *pos << '\n';
    // }

    std::string s {"device"};

    for (std::string::iterator pos = s.begin(); pos < s.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    // C++11:
    // for (auto pos = s.begin(); pos < s.end(); ++pos) {
    //     std::cout << *pos << '\n';
    // }
}
