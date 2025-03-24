// before C++23:
// E.g:
// MSVC and ICC: __assume(expr)
// Clang: __builtin_assume(expr)
// GCC: Emulated with:
//      if (expr) {} else { __builtin_unreachable(); }

int divide_by_32(int x) {
#ifdef __GNUC__
    if (x >= 0) {
    } else {
        __builtin_unreachable();
    }
#elif defined(_MSC_VER)
    __assume(x >= 0);
#elif defined(__clang__)
    __builtin_assume(x >= 0);
#endif
    return x / 32;
}

// since C++23: standard way to express assumptions
// [[assume(expr)]]

int _divide_by_32(int x) {
    [[assume(x >= 0)]];
    return x / 32;
}
