// since C++17:
// `auto` + Structured binding

#include <map>
#include <string>

int main() {

    std::map<std::string, std::string> table;
    for (auto &[k, v] : table) { // OK：The part of `k` will automatically include `const`.
        k = "hello"; // ERROR：`k` is deduced as `std::string const &` and is non-modifiable.
        v = "world"; // OK：v is deduced as std::string & and is modifiable.
    }

    return 0;
}
