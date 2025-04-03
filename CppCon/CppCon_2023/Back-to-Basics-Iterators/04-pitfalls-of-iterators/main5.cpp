
// Removing Algorithm (C++98/C++11)
//
// - Content after std::remove(..., 3):
// - Removing algorithms do not remove
//   - Instead, they replace removed elements and return the new end
//   - Reason:
//      - Iterators operate on elements, not no containers
//          - Can only read, write, and go to another value

#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>

int main() {
    std::list<int> coll {6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6};

    for (int elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // remove all elements with value 3
    auto newEnd = std::remove(coll.begin(),
                              coll.end(), /* range */
                              3);         /* value */

    for (int elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    for (auto pos = coll.begin(); pos != newEnd; ++pos) { // print elems up to new end
        std::cout << *pos << ' ';
    }
    std::cout << '\n';

    // Removing Algorithm and Views (C++20)
    for (int elem : std::ranges::subrange(coll.begin(), newEnd)) { // elems til new end
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    auto not3 = [](auto const &elem) {
        return elem != 3;
    };

    // print all elements not having value 3:
    for (int elem : coll | std::views::filter(not3)) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
