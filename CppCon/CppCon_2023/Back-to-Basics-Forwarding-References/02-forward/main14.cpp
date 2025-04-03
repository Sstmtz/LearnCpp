
// Perfect Forwarding of the returned value

#include <utility>

template <typename T>
decltype(auto) wrapper(T &&v) {
    auto &&ret = foo1(std::forward<T>(v));
    // ...
    return foo2(std::forward<decltype(ret)>(ret));
}

// Note: Similarly to lvalue references to const and rvalue references, auto&& can be
// used to extend the lifetimes of temporary objects
