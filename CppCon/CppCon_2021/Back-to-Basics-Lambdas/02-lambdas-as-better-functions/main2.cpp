// Lambdas Captures

// - Lambdas
//   - Captures behavior parameters
//     - Functionality can depend on run-time parameters
//   - to deal with call parameters

#include <algorithm>
#include <iostream>
#include <vector>

// int main() {
//     std::vector<int> coll {0, 8, 15, 42, 11, 1, 77, -1, 3};
//
//     int max = 30;
//
//     // count number of elements less or equal max
//     int num = std::count_if(coll.begin(),
//                             coll.end(),       // range
//                             [max](int elem) { // criterion (defined on the fly)
//                                 return elem < max;
//                             });
//     std::cout << "elems " << max << ": " << num << '\n';
// }

// Generic Lambdas (since C++14)

// - Call arguments may have a generic type
//   - auto, const auto&, ...
// - Not possible in normal functions before C++20

int main() {
    std::vector<int> coll {0, 8, 15, 42, 11, 1, 77, -1, 3};

    int max = 30;

    // count number of elements less or equal max
    int num = std::count_if(coll.begin(),
                            coll.end(),        // range
                            [max](auto elem) { // criterion (defined on the fly)
                                return elem < max;
                            });
    std::cout << "elems " << max << ": " << num << '\n';
}
