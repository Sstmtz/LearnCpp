
// Don't Specialize Function Templates

// If you want to a full specialization,
// create a non-template overload

#include <list>

template <class T>
    requires some_condition<T>
void do_something(T const &arg) {
    // ... something
}

void do_something(char const *s) {
    // ... something different ...
}

// If you want to a partial specialization,
// create template overload

template <class C>
    requires is_container<C>
void process_collection(C const &c) {
    // ... processing
}

template <class T>
void process_collection(std::list<T> const &c) {
    // ... list processing
}

int main() {
    return 0;
}
