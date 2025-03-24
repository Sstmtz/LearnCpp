#include <memory>
#include <optional>
#include <string_view>

// before C++17:
// return default int on parse error
int to_int(std::string_view s);
// throw no parse error
int to_int(std::string_view s);
// return false on parse error
int to_int(std::string_view s);
// return null on parse error
std::unique_ptr<int> to_int(std::string_view s);

// since C++17:
std::optional<int> to_int(std::string_view s);
