
// Finding the last element in a range
// ranges::find_last(): matching a given value
// ranges::find_last_if(): for which a given predicate returns true
// ranges::find_last_if_not(): for which a given predicate returns false
// Return sub range starting at found element until end of the range, or {last, last} if not found

// ranges::contains(): true if a range contains a given element
// ranges::contains_subrange(): true if a range containss another given range as a subrange

#include <algorithm>
#include <print>
#include <vector>

int main() {
    std::vector v1 {11, 22, 33, 44};
    std::vector v2 {33, 44};
    std::println("{}", std::ranges::contains(v1, 22));          // true
    std::println("{}", std::ranges::contains_subrange(v1, v2)); // true
}
