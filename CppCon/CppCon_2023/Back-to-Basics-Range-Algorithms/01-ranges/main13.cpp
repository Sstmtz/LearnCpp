
// Introducing std::reduce() (C++17)

#include <cstdlib>
#include <execution>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main() {
    std::vector<double> values = {};

    // Sum up the age of all persons
    auto const sum = std::reduce(std::execution::par, std::begin(values), std::end(values), double {});
    // auto const sum = std::reduce(std::execution::par, std::begin(values), std::end(values));

    std::cout << "Total sum = " << sum << '\n';

    // ...

    return EXIT_SUCCESS;
}
