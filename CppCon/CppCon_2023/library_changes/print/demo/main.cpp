#include <format>
#include <iostream>
#include <map>
#include <print>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct Point {
    int x, y;
};

template <>
struct std::formatter<Point> {
    constexpr auto parse(std::format_parse_context &ctx) {
        return ctx.begin();
    }

    auto format(Point const &p, std::format_context &ctx) const {
        return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
    }
};

int main() {
    // std::print() and std::println() make std::format() easier

    std::string name {"CppCon2023"};
    // Old-Style cout/format() pattern
    std::cout << std::format("Hello {} 2023!\n", name);
    // C++23 print()
    std::print("Hello {} 2023!\n", name);
    // C++23 println()
    std::println("Hello {} 2023!", name);

    // by implementing std::formatter, you can provide formatting support for custom types:

    Point p {3, 4};
    std::println("Point: {}", p); // Output: Point: (3, 4)

    // format ranges using std::format(), std::print() and std::println()
    // but they currently do not support  container types

    // std::vector<std::pair<int, int>> v {
    //   {1, 2},
    //   {3, 4}
    // };
    // std::println("{}", v); // [(1, 2), (3, 4)]
    //
    // std::set<std::pair<int, int>> s {
    //   {1, 2},
    //   {3, 4}
    // };
    // std::println("{}", s); // {(1, 2), (3, 4)}
    //
    // std::map<int, int> m {
    //   {1, 2},
    //   {3, 4}
    // };
    // std::println("{}", m); // {1: 2, 3: 4}
    //
    // // range formatting specifiers
    //
    // using namespace std::string_literals;
    // std::vector strings {"Hello"s, "World!\t2023"s};
    // std::println("{}", strings);   // ["Hello", "World!\t2023"]
    // std::println("{::}", strings); // [Hello, World!    2023]
    //
    // std::vector<std::vector<int>> vv {
    //   {11, 22},
    //   {33, 44, 55}
    // };
    // std::println("{}", vv);         // [[11, 22], [33, 44, 55]]
    // std::println("{:n}", vv);       // [11, 22], [33, 44, 55]
    // std::println("{:n:n}", vv);     // 11, 22, 33, 44, 55
    // std::println("{:n:n:*^4}", vv); // *11*, *22*, *33*, *44*, *55*
}
