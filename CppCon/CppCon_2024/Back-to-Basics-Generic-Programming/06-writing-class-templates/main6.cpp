
// typename

// T::A * B(T::C(T::D))
template <class T>
void do_something(T t) {
    // ...
    T::value_type *p(T::addr(T::object));
    // ERROR: dependent-name 'T::value_type' is parsed as a non-type,
    // but instatiation yields a type
    // Note: Say 'typename T::value_type' if a type is meant
    // ...
}

template <class T>
void do_something2(T t) {
    // ...
    typename T::value_type *p(T::addr(T::object)); // OK
    // ...
}

int main() {
    return 0;
}
