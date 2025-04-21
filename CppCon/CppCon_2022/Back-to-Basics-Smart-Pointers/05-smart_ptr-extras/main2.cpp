// Allasing Constructor

// Two shared_ptrs use same control block, but have unrelated object pointers

// Useful for pointers to subobjects of managed objects

#include <memory>

struct Outer {
    int a;
    Inner inner;
};

void f(std::shared_ptr<Outer> op) {
    std::shared_ptr<Inner> ip(op, &op->inner);
    // ...
}
