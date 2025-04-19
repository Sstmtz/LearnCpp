// Capture by Value

// - Lambdas are stateless by default
//   - Not allowed to modified values captured by-value
// - `mutable` makes them stateful (modifications allowed)

// auto changed = [prev = 0](auto val) {
//     bool changed = prev != val;
//     prev = val; // ERROR: prev is read-only copy
//     return changed;
// };

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

auto changed = [prev = 0](auto val) mutable {
    bool changed = prev != val;
    prev = val; // OK: due to mutable
    return changed;
};

int main() {
    std::vector<int> coll {7, 42, 42, 0, 3, 3, 7};
    std::copy_if(coll.begin(), coll.end(), std::ostream_iterator<int> {std::cout, " "}, changed);
    std::cout << '\n';

    // Standard algorithm take callables by value
    // - Operate on a copy of changed
    std::copy_if(coll.begin(), coll.end(), std::ostream_iterator<int> {std::cout, " "}, changed);
    std::cout << '\n';

    changed(7);
    std::copy_if(coll.begin(), coll.end(), std::ostream_iterator<int> {std::cout, " "}, changed);
    std::cout << '\n';
}
