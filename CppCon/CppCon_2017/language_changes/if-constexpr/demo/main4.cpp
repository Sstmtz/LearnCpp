#include <cstddef>
#include <iterator>
#include <string>

struct person {
    int         m_id;
    std::string m_name;
    int         m_age;

    int const &get_id() {
        return m_id;
    }

    std::string const &get_name() {
        return m_name;
    }

    int const &get_age() {
        return m_age;
    }
};

// before C++17:
template <std::size_t I>
auto &get(person &p);

template <>
auto &get<0>(person &p) {
    return p.get_id();
}

template <>
auto &get<1>(person &p) {
    return p.get_name();
}

template <>
auto &get<2>(person &p) {
    return p.get_age();
}

// since C++17:
template <std::size_t I>
auto &get(person p) {
    if constexpr (I == 0) {
        return p.get_id();
    } else if constexpr (I == 1) {
        return p.get_name();
    } else if constexpr (I == 2) {
        return p.get_age();
    }
}
