#include <concepts>
#include <iostream>
#include <list>
#include <vector>

// C++20: Constraints with Concepts Can Subsume

template <typename CollT>
concept HasSize = requires(CollT c) {
    { c.size() } -> std::convertible_to<int>;
};

template <typename CollT>
concept HasIndexOp = requires(CollT c) { c[0]; };

template <typename CollT>
    requires HasSize<CollT> // has to support size()
void foo(CollT &coll) {
    std::cout << "foo() for container with size() \n";
}

template <typename CollT>
// HasSize<> && HasIndexOp <> subsume HasSize<>
    requires HasSize<CollT> && HasIndexOp<CollT> // has to support size() and []
void foo(CollT &coll) {
    std::cout << "foo() for container with size() and [] \n";
}

int main() {
    std::list<int>   lst {0, 8, 15};
    std::vector<int> vec {0, 8, 15};

    foo(lst); // OK: calls first foo()
    foo(vec); // OK: calls second foo()
}
