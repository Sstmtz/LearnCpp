// Since C++11:
// Range-Based for loop

#include <iostream>
#include <vector>

void print(std::vector<int> const &vec) {
    for (auto const i : vec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    for (auto i : arr) { // int i
        i += 1;
    }
    print(arr);

    for (auto &i : arr) { // int& i
        i += 1;
    }
    print(arr);

    // for (auto const &i : arr) { // int const& i
    //     i += 1;                 // ERROR: const ref isn't modified
    // }
}
