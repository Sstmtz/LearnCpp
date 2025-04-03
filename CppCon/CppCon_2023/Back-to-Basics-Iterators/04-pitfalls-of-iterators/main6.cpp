
// Filter Views Intern (C++20)

#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> coll {0, 8, 15, 47, 11, 42};

    auto greater40 = [](auto const &elem) {
        return elem > 40;
    };

    auto v1 = coll | std::views::filter(greater40);

    auto pos = v1.begin();
    std::cout << *pos;
    ++pos;
    std::cout << *pos;
    //...
    while (pos != v1.end())
        ;
}
