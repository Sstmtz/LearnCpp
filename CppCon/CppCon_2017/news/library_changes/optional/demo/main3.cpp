#include <optional>
#include <string>

auto slice(std::string str, std::optional<int> start, std::optional<int> end) {
    auto s = start.value_or(0);
    auto e = end.value_or(str.size());
    return str.substr(s, e - s);
}
