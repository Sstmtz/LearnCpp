
// Introducing std::accumulate() (C++20)

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main() {
    std::vector<double> values = {};

    // Sum up the age of all persons
    auto const sum = std::accumulate(std::begin(values), std::end(values), 0);
    // auto const sum = std::accumulate(std::begin(values), std::end(values), double {});

    std::cout << "Total sum = " << sum << '\n';

    // ...

    return EXIT_SUCCESS;
}
