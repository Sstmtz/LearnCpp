
// Perfect Returning

#include <utility>

// auto always returns by value
template <typename T>
auto wrapper(T &&v) {
    return foo(std::forward<T>(v));
}

// auto always returns a reference (i.e. to local object)
template <typename T>
auto &&wrapper(T &&v) {
    return foo(std::forward<T>(v));
}

// decltype(auto) perfectly returns:
// - temporary by value
// - reference by reference
template <typename T>
decltype(auto) wrapper(T &&v) {
    return foo(std::forward<T>(v));
}
