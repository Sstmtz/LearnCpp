// Synatx:
// if consteval { /* A */ } else { /* B */ }
// 1. no condition
// 2. braces are mandary
// Effect: if this statement is evaluated during constant evaluation,
// then A is executed, otherwise B

// We have std::is_constant_evaluated(), so what's wrong with:
// if (std::is_constant_evaluated()) { /* A */ } else { /* B */}

// It's equalivant except for:
// 1. With an `if consteval` block you can call immediate (consteval) functions,
// which you cannot do in /*A*/ above
// 2. `if consteval` cannot be used wrong
// is_constant_evaluated() can:
// if constexpr (std::is_constant_evaluated()) { /* A */ } else { /* B */}

consteval int f(int i) {
    return i;
}

constexpr int g(int i) {
    if consteval {
        return f(i) + 1; // immediate function context
    } else {
        return 42;
    }
}

consteval int h(int i) {
    return f(i) + 1; // immediate function context
}

int main() {
    return 0;
}
