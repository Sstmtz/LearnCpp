#include <deque>
#include <string>

#if __cpp_lib_flat_map >= 202207L
    #include <flat_map>
#endif

#if __cpp_lib_flat_set >= 202207L
    #include <flat_set>
#endif

using namespace std::string_literals;

int main() {

    std::flat_map<int, std::string> myMap;
    myMap[2023] = "CppCon"s;

    std::flat_map<int, std::string, std::less<int>, std::deque<int>, std::deque<std::string>> myMap;
}
