#include <cstddef>

// Non-Type Template Parameters
template <class T, std::size_t N>
class array {
    T m_data[N];

public:
    constexpr std::size_t size() const {
        return N;
    }

    // ...
};

// Class Template Member Functions(In-class definition)
template <class T>
struct A {
    T f() const {
        return T {};
    }

    template <class U>
    T g(U u) const {
        return static_cast<T>(u);
    }
};

// Class Template Member Functions(Out-of-class definition)
template <class T>
struct B {
    T f() const;
    template <class U>
    T g(U u) const;
};

template <class T>
T B<T>::f() const {
    return T {};
}

template <class T>
template <class U>
T B<T>::g(U u) const {
    return static_cast<T>(u);
}

int main() {
    return 0;
}
