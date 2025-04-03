
// Processing Containers and Views (C++20)

#include <iostream>
#include <list>
#include <ranges>
#include <vector>

void print(auto const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec {0, 8, 15, 47, 11, 42, 1};
    std::list<int>   lst {0, 8, 15, 47, 11, 42, 1};

    print(vec);
    print(lst);

    auto gt40 = [](auto const &elem) {
        return elem > 40;
    };

    for (auto const &elem : vec | std::views::filter(gt40)) { // OK
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // print(vec | std::views::filter(gt40)); // ERROR
    print(vec | std::views::drop(3)); // OK
    // print(lst | std::views::drop(3)); // ERROR
}
