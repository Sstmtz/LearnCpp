
// Deducible Template Parameters

// Can't deduce the parent type of a function parameter

template <class T>
struct A {
    using type = T;
};

template <class T>
void g(typename A<T>::type arg) {}

int main() {
    // g(2); // ERROR: no matching function for call to 'g(int)'
    // Note: couldn't deduce template parameter 'T'
}
