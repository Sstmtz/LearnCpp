#include <iostream>

// Additionally, C++14 also supports `decltype(auto)`,
// which is commonly used for perfect forwarding.
template <class F, class... Args>
decltype(auto) PerfectForward(F fun, Args &&...args) {
    return fun(std::forward<Args>(args)...);
}

// The effect of declaring the return type as `decltype(auto)` is equivalent to replacing the return
// type with `decltype((expression))`.
int const i = 0;

decltype(auto) func() {
    return i;
}

// equivalent to:
// decltype((i + 1)) func() {
//     return i + 1;
// }

// also equivalent to:
// int func() {
//     return i + 1;
// }

decltype(auto) func2() {
    return std::move(i);
}

// equivalent to:
// decltype((std::move(i))) func2() {
//     return std::move(i);
// }

// also equivalent to:
// int &&func2() {
//     return std::move(i);
// }

int main() {

    auto i = 0;                          // int i = 0
    auto &ref = i;                       // int &ref = i
    auto const &cref = i;                // int const &cref = i
    auto &&rvref = std::move(i);         // int &&rvref = move(i)

    decltype(auto) j = i;                // int j = i
    decltype(auto) k = ref;              // int &k = ref
    decltype(auto) l = cref;             // int const &l = cref
    decltype(auto) m = std::move(rvref); // int &&m = rvref

    return 0;
}
