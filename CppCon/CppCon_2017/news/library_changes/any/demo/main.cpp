#include <any>
#include <tuple>
#include <vector>

int main() {
    std::vector<std::any> v;
    v.push_back("Hello CppCon2017");
    v.push_back(std::tuple(3.14, true));
    v.push_back(42);
    v.push_back(std::vector<std::any> {});
}
