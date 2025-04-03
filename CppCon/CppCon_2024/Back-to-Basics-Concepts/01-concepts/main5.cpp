#include <set>
#include <vector>

// C++20: Testing Concepts
//
// Concepts are compile-time Boolean values

template <typename CollT>
concept HasPushBack = requires(CollT c, CollT::value_type v) {
    c.pushback(v); // OOPS: spelling error
};

int main() {
    static_assert(HasPushBack<std::vector<int>>);
    static_assert(! HasPushBack<std::set<int>>);

    std::vector<int> coll1;
    static_assert(HasPushBack<decltype(coll1)>);
}
