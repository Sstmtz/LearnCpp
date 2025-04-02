#include <array>
#include <complex>
#include <vector>

// C++17: Class Template Argument Deduction (CTAD)
//
// Constructors deduce template parameters (since C++17)

int main() {
    std::complex<int> c1(5, 3);               // all C++ versions
    std::complex<int> c2 {5, 3};              // OK (since C++17)

    std::complex c3 {5, 3};                   // deduces std::complex<int>
    std::complex c4(5, 3);                    // deduces std::complex<int>
    std::complex c5 = 42;                     // deduces std::complex<int>

    std::vector<int> v {0, 8, 15};            // since C++11
    std::vector      v2 {0, 8, 15};           // deduces std::vector<int>
    std::vector      v3 {"all", "right"};     // Note: deduces vector<const char*>
    std::vector      v4 {v.begin(), v.end()}; // Note: vector of two iterators (not the elements)
                                              // deduces vector<vector<int>::iterator>
    // Don't use CTAD unless deduction is obvious
    std::vector<int> v5 {v.begin(), v.end()};   // OK: copies elements from v

    std::array a {0, 8, 15, 7, 4, 1, 42, 9, 5}; // deduces std::array<int, 9>
}

// CTAD for std::vector<>
// namespace std {
//     template <typename ElemT, typename Allocator = allocator<T>>
//     class vector {
//     public:
//         vector() noexcept(noexcept(Allocator()));
//         explicit vector(const Allocator&) noexcept;
//         explicit vector(size_t n, const Allocator& = Allocator());
//         vector(size_t n, const ElemT& value, const Allocator& = Allocator());
//         template<typename T>
//             vector(Iter beg, Iter end, const Allocator& = Allocator());
//         vector(const vector& x);
//         vector(vector&&) noexcept;
//         vector(const vector&, const Allocator&);
//         vector(vector&&, const Allocator&);
//         vector(initializer_list<ElemT>, const Allocator& = Allocator());
//         // ...
//     };
// }; // namespace std

// Overload resolution:
// 1. Number of arugments must match
// 2. Types must fit(incl. implict conversions)
// 3. Choose best match:
// - Perfect match over template
// - Template over conversion
// - For non-empty brace initialization, std::initializer_list<> has highest priority
