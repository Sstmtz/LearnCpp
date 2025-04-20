// Example: The Design of the STL

// In the design of the STL
// - ... containers are values
//   - copy implies a deep copy
//   - const means const
// - ...algorithms take arguments by value

#include <vector>

int main() {
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int> v2 {};
    v2 = v1; // deep copy

    std::vector<int> const w {v1};
}

template <typename InputIt, typename OutputIt, typename UnaryPredicate>
constexpr OutputIt copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred);
