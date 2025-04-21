// C++03 Template Concerns

// These issues were especially noticeable in template contexts:

template <typename T>
void f(T const &t) {
    int x = t;            // Is this a narrowing conversions?
    T obj1;               // Is obj1 uninitialized?
    T obj2 = T();         // Is T copy constructible?
    T obj3 = {1, "Sulu"}; // Does T support aggregate-init?
}
