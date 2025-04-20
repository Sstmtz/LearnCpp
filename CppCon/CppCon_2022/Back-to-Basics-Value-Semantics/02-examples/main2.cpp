// Example: std::optional

#include <expected>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

// Return default int on parse error
int to_int_1(std::string_view s);

// Throw on parse error
int to_int_2(std::string_view s);

// Return false on parse error
int to_int_3(std::string_view s, int &);

// Return null on parse error
std::unique_ptr<int> to_int_4(std::string_view s);

std::optional<int> to_int_5(std::string_view s);

// There is no question of ownership
// There is no question of semantics
// There is no exception overhead
// It is efficient (return value optimisation (RVO) and move semantics)
// It's simple!
//
// The main disadvantage: You cannot communicate the reason for a failure

std::expected<int, std::string> to_int_6(std::string_view s);

// There is no question of ownership
// There is no question of semantics
// There is no exception overhead
// It is efficient (return value optimisation (RVO) and move semantics)
// It's simple!

int main() {
    return 0;
}
