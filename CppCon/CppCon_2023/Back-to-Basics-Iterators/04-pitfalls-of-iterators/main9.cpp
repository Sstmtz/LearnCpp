
// Using the Filter View (C++20)
//
// - Max use case of a filter:
//   - Fix an attribute that some elements might have

#include <iostream>
#include <ranges>
#include <vector>

void print(auto const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> coll {1, 4, 7, 10};
    print(coll);

    auto isEven = [](auto &&i) {
        return i % 2 == 0;
    };

    auto collEven = coll | std::views::filter(isEven);

    // add 2 to even elements:
    for (int &i : collEven) {
        i += 2;
    }
    print(coll);

    // add 2 to even elements:
    for (int &i : collEven) {
        i += 2;
    }
    print(coll);

    // increment even elements:
    for (int &i : collEven) {
        i += 1;
    }
    print(coll);

    // increment even elements:
    for (int &i : collEven) {
        i += 1;
    }
    print(coll);

    // as a shaman:
    // for (auto &m : monsters | std::views::filter(isDead)) {
    //     m.resurrect(); // UB: because no longer dead
    //     m.burn();      // OK: because it is still dead
    // }
}
