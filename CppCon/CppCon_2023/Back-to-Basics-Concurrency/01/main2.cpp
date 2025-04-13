// C++ parallel algorithms
//
// Existing algorithms

#include <algorithm>
#include <execution>
#include <vector>

struct Item {
public:
    Item(std::string const &n, double p) : name(n), price(p) {}

private:
    std::string name;
    double price;

public:
    [[nodiscard]] double get_price() const {
        return price;
    }
};

struct compare_by_price {
    bool operator()(Item const &a, Item const &b) const {
        return a.get_price() < b.get_price();
    }
};

int main() {

    // If using standard algorithms already, add execution policy argument

    std::vector<Item> items = {
      {"Item A", 10.99},
      {"Item B",  5.49},
      {"Item C",  7.99}
    };

    std::vector<int> v = {11, 42, 45, 0, 24, -1, 29};

    // std::sort(items.begin(), items.end(), compare_by_price {});
    // std::find(v.begin(), v.end(), -1);

    std::sort(std::execution::par, items.begin(), items.end(), compare_by_price {});
    std::fill(std::execution::par_unseq, v.begin(), v.end(), -1);
}
