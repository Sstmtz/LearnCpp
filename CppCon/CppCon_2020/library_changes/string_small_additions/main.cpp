#include <string>
#include <map>
#include <iostream>

int main() {
    std::string str{ "Hello World!" };
    bool b{ str.starts_with( "Hello" ) };
    std::cout << b << '\n';

    using namespace std::string_literals;
    std::map myMap{ std::pair{ 1, "one"s }, { 2, "two"s }, { 3, "three"s } };
    bool result{ myMap.contains( 2 ) };
    std::cout << result << '\n';
}
