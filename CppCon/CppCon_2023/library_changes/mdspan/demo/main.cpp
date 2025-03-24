#include <cstddef>

#if __cpp_lib_mdspan >= 202207L
    #include <mdspan>
#endif

// std::mdspan
// 1. multidimensional array view
// 2. multidimensional extension of std::span (from C++20)
// 3. supports different layout policies

// std::submdspan
// 1. an mdspan viewing a subset of an existing mdspan (=slice)

int main() {
    int *data {/* ... */};

    auto mySpan {std::mdspan(data, 2, 2)};

    for (size_t i {0}; i < mySpan.extents().extent(0); ++i) {
        for (size_t j {0}; j < mySpan.extents().extent(1); ++j) {
            mySpan[i, j] = i * 1000 + j;
        }
    }
}
