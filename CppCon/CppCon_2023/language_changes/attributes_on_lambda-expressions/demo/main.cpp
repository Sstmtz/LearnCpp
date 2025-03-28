
// before C++23,
// you can specify attributes for the `function object` generated by a lambda expression
// E.g:
auto a = []() [[deprecated]] {
    return 42;
};

// since C++23,
// also allows attributes for the `function call operator` of the
// generated function object
// E.g:
auto a_ = [] [[nodiscard]] () [[deprecated]] {
    return 42;
};

// note:
// [[nodiscard]]: attribute on the `function call operator` of the function object
// [[deprecated]]: attribute on the `function object`

int main() {
    return 0;
}
