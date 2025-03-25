#include <algorithm>
#include <functional>
#include <iterator>
#include <print>
#include <ranges>
#include <string>
#include <vector>

// views::zip: a view with the n^th element a tuple of the n^th elements of all given views.
// views::zip_transform: a view with the n^th element the result of applying a given operator to the n^th elements of all given views.

// views::adjacent: a view with each element a tuple of references to N adjacent elements from the original view.
// views::adjacent_transform: a view with each element the result of applying an operator to N adjacent element.

// Two helper types:
// views::pairwise = views::adjacent<2>
// views::pairwise_transform = views::adjacent_transform<2>

// views::slide: a view with each element a tuple of references to adjacent elements from the original view (sliding window).
// - similar to views::adjacent, but window size is runtime parameter for slide().

// views::chunk: a view with each element a tuple of N references to next N elements of the original view.

// views::chunk_by(): a view with each element a tuple of references to the next N elements of the original view that match given prdicate.
// views::join_with(): joins elements of a range using a given separator.
// views::stride(): a view providing an evenly-spaced strided subset of a given range.
// views::repeat(): a view repeating a given value infinitely or a specified number of times.
// views::cartesian_product(): a view of tuples representing the cartesian product of n given ranges
// views::as_rvalue(): a view representing an underlying range but whole elements are rvalues.

int main() {
    std::vector v1 {1, 2};
    std::vector v2 {'a', 'b', 'c'};
    std::vector v3 {3, 4, 5};
    auto        r1 {std::views::zip(v1, v2)};                              // {(1, 'a'), (2, 'b')}
    auto        r2 {std::views::zip_transform(std::multiplies(), v1, v2)}; // {3, 8}

    std::vector v4 {1, 2, 3, 4};
    auto        r3 {v4 | std::views::adjacent<2>};                              // {(1, 2),(2, 3),(3, 4)}
    auto        r4 {v4 | std::views::adjacent_transform<2>(std::multiplies())}; // {2, 6, 12}

    std::vector v5 {'a', 'b', 'c'};
    auto        r5 {v5 | std::views::pairwise};                        // {('a', 'b'),('b', 'c')}
    std::vector v6 {3, 4, 5};
    auto        r6 {v6 | std::views::pairwise_transform(std::plus())}; // {7 ,9}

    std::vector v7 {1, 2, 3, 4, 5};
    auto        r7 {std::views::slide(2)};

    std::vector v8 {1, 2, 3, 4, 5};
    auto        r8 {v8 | std::views::chunk(2)}; // {(1, 2), (3, 4), (5)}

    std::vector v9 {1, 2, 2, 3, 0, 4, 5, 2};
    auto        r9 {v9 | std::views::chunk_by(std::ranges::less_equal({}))}; // {(1, 2, 2, 3), (0, 4, 5), (2)}

    std::vector<std::string> v10 {"Hello", "World", "!"};
    for (auto c : v10 | std::views::join_with('\n')) {
        std::print("{}", c);
    }
    // Hello
    // World
    // !

    std::vector v11 {1, 2, 3, 4, 5};
    auto        r10 {v11 | std::views::stride(2)}; // {1, 3, 5}

    auto r11 {std::views::repeat(2, 3)};           // {2, 2, 2}
    auto r22 {std::views::repeat(2)};              // {2, 2, 2, ...}

    std::vector v12 {0, 1, 2};
    for (auto &&[a, b] : std::views::cartesian_product(v12, v12)) {
        std::println("{} {}", a, b);
    }
    // 0 0
    // 0 1
    // 0 2
    // 1 0
    // 1 1
    // 1 2
    // ...

    std::vector<std::string> words {"Hello", "World", "2023"};
    std::vector<std::string> moveWords;
    std::ranges::copy(words | std::views::as_rvalue, std::back_inserter(moveWords));

    return 0;
}
