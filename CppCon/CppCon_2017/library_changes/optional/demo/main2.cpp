#include <iterator>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>

std::optional<int> to_int(std::string_view s) {
    std::optional<int> oi;
    int i;

    std::string str(s);
    if (std::stringstream stm(str); (stm >> i)) {
        if (stm.get() == std::char_traits<char>::eof()) {
            oi = i;
        }
    }

    return oi;
}

int main() {
    return 0;
}
