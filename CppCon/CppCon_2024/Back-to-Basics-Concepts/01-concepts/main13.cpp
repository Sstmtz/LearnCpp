#include <ranges>

// C++20: Concept std::ranges::range

template <typename T>
concept range = requires(T &t) {
    std::ranges::begin(t);
    std::ranges::end(t);
};
// ...

// T models range only if
// 1. [std::ranges::begin(t), std::ranges::end(t)] denotes a range,
// 2. both std::ranges::begin(t) and std::ranges::end(t) are amortized constant time and non-modifying, and
// 3. if the type of std::ranges::begin(t) models forward_iterator, std::ranges::begin(t) is equality preserving.
//
// Semantic/runtime requirements:
// 1. Cannot be checked by compilers.
// 2. Documentation only.
