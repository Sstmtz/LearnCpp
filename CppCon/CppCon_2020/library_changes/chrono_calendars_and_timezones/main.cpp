#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

int main() {
    auto y1 = {std::chrono::year {2020}};
    auto y2 = {2020y};
    // std::cout << y1 << ' ' << y2 << '\n';

    auto m1 = {std::chrono::month {9}};
    auto m2 = {std::chrono::September};
    // std::cout << m1 << ' ' << m2 << '\n';

    auto d1 = {std::chrono::day {15}};
    auto d2 = {15d};
    // std::cout << d1 << ' ' << d2 << '\n';

    auto date1 = std::chrono::year_month_day {2020y, std::chrono::September, 15d};
    auto date2 = {2020y / std::chrono::September / 15d};
    auto date3 = std::chrono::year_month_day {std::chrono::Monday[3] / std::chrono::September / 2020};
    // std::cout << date1 << ' ' << date2 << ' ' << date3 << '\n';

    std::chrono::weeks w {1}; // 1 week
    std::chrono::days  d {w}; // convert 1 week into days (7 days)
    std::cout << w << ' ' << d << '\n';

    // using sys_seconds = std::chrono::sys_time<std::chrono::seconds>;
    // using sys_days = std::chrono::sys_time<std::chrono::days>;

    std::chrono::system_clock::time_point t {std::chrono::sys_days {2020y / std::chrono::September / 15d}}; // date -> time_point
    auto yearmonthday {std::chrono::year_month_day {std::chrono::floor<std::chrono::days>(t)}};             // time_point -> date
    std::cout << t << '\n';
    std::cout << yearmonthday << '\n';

    auto utc {std::chrono::sys_days {2020y / std::chrono::September / 15d} + 9h + 35min + 10s}; // 2020-09-15 09:35:10 UTC
    std::cout << utc << '\n';

    std::chrono::zoned_time denver {"America/Denver", utc};
    std::cout << denver << '\n';
    auto localt {
      std::chrono::zoned_time {std::chrono::current_zone(), std::chrono::system_clock::now()}
    };
    std::cout << localt << '\n';
}
