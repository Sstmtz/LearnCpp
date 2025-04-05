#include <initializer_list>
#include <vector>

// Overload sets

// Avoid complicated overload sets

// explicit vector(size_type count);
// vector(std::initializer_list<T> init);

// vector(size_type count, const T& value);
// vector(std::initializer_list<T> init);

int main() {
    std::vector<int> a(100);       // 100 elements with value 0
    std::vector<int> b {100};      // 1 element with value 100

    std::vector<int> c(100, 200);  // 100 elements with value 200
    std::vector<int> d {100, 200}; // 2 elements with value 100, 200

    std::vector<int *> e(100);     // 100 elements with value nullptr
    std::vector<int *> f {100};    // 100 elements with value nullptr
}
