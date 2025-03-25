#include <expected>
#include <string>

// std::expected<T, E> contains either
// 1. a value type T, the expected value type
// 2. a value type E, an error type
// guaranteed to never be empty
// std::unexpected() is used to create an unexpected value

// member functions:
// has_value(): true if the expected contains a value, false otherwise.
// value(): return reference to the contained value, or throws bad_expected_access if no value.
// error(): returns reference to the error.

using namespace std::string_literals;

int main() {
    std::expected<int, std::string> a {21};
    std::expected<int, std::string> b {std::unexpected("Some error"s)};
}
