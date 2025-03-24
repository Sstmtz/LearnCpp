#include <string>
#include <string_view>
#include <variant>

// before C++17:
struct convert_result {
    union data_type {
        bool        b;
        int         i;
        double      d;
        std::string s;
    };

    enum kind_type {
        BOOL,
        INT,
        DOUBLE,
        STRING
    };

    data_type data;
    kind_type kind;
};

// since C++17:
std::variant<bool, int, double, std::string> convert(std::string_view s);

int main() {
    return 0;
}
