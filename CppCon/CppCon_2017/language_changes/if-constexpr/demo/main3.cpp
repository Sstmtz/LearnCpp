#include <iterator>
#include <type_traits>

// before C++17:
template <typename Iterator, typename Dist>
void advance(Iterator &i, Dist n) {
    typename std::iterator_traits<Iterator>::iterator_category c;
    advance_impl(i, n, c);
}

template <typename Iterator, typename Dist>
void advance_impl(Iterator &i, Dist n, std::random_access_iterator_tag) {
    i += n;
}

template <typename Iterator, typename Dist>
void advance_impl(Iterator &i, Dist n, std::bidirectional_iterator_tag) {
    if (n >= 0) {
        while (n--) {
            ++i;
        }
    } else {
        while (n++) {
            --i;
        }
    }
}

template <typename Iterator, typename Dist>
void advance_impl(Iterator &i, Dist n, std::input_iterator_tag) {
    while (n--) {
        ++i;
    }
}

// since C++17:
template <typename Iterator, typename Dist>
void advance2(Iterator &i, Dist n) {
    if constexpr (std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>) {
        i += n;
    } else if constexpr (std::is_same_v<typename std::iterator_traits<Iterator>::iterator_category, std::bidirectional_iterator_tag>) {
        if (n >= 0) {
            while (n--) {
                ++i;
            }
        } else {
            while (n++) {
                --i;
            }
        }
    } else { // std::input_iterator_tag
        while (n--) {
            ++i;
        }
    }
}

int main() {
    return 0;
}
