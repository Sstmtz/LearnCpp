#include <array>
#include <map>
#include <tuple>

struct point_3d {
    double x, y, z;
};

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value> &m, F f) {
    for (auto &&[key, value] : m) {
        value = f(key);
    }
}

int main() {
    // Before C++17:
    point_3d p = {1, 2, 3};
    double   x = p.x;
    double   y = p.y;
    double   z = p.z;
    // Or use std::tuple + std::tie
    std::tuple<double, double, double> t = {1, 2, 3};
    double                             x_, y_, z_;
    std::tie(x_, y_, z_) = t;

    // Common issues:
    // double &x, &y, &z;       // 1. compile error: uninitialized refs

    // std::tie( y, y, z ) = t; // 2. no warning? repeated name

    // double const x, y, z;
    // std::tie( y, y, z ) = t; // 3. compile error: assignment to const

    // point_3d p = {1, ,2 ,3}
    // std::array<double, 3> p = {1, 2, ,3};
    // std::tie(x, y, z) = p // 4. compile error: c isn't a std::tuple

    // since C++17:
    // auto [a, b, ...] = obj;
    // use `auto` deduction rules(auto const, auto&, auto&&, etc).
    // the type of `obj` must be destructurable:
    point_3d p1 = {1, 2, 3};
    auto [x1, y1, z1] = p1;
    // so, std::tuple is ok
    std::tuple<double, double, double> t1 = {1, 2, 3};
    auto [x1_, y1_, z1_] = t1;
    // so, std::array is ok
    std::array<double, 3> c = {1, 2, 3};
    auto [_x1, _y1, _z1] = c;
}
