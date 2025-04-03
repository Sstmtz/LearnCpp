#include <ranges>
#include <type_traits>

// C++20: Granularity of Concepts

template <typename CollT>
concept SequenceCont = std::ranges::range<CollT> && requires(std::remove_cvref_t<CollT> c, std::ranges::range_value_t<CollT> v) {
    c.push_back(v);
    c.pop_back();
    c.insert(c.begin(), v);
    c.erase(c.begin());
    c.clear();
    std::remove_cvref_t<CollT> {v, v, v}; // init-list support
    c = {v, v, v};
    { c < c } -> std::convertible_to<bool>;
    // ...
}; // Combine multiple requirements into general-purpose concepts

template <typename CollT, typename T>
    requires SequenceCont<CollT>
void add(CollT &coll, T const &val) {
    coll.push_back(val);
}
