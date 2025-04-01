#include <tuple>
#include <vector>

template <typename... TFoos>
class Baz {
public:
    template <typename T>
    auto store(T value) {
        return std::get<std::vector<T>>(data).push_back(value);
    }

private:
    std::tuple<std::vector<TFoos>...> data {};
};

int main() {
    return 0;
}
