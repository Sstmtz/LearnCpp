#include <string>
#include <utility>

template <class T>
void swap_pointed_to(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Using a template
int main() {
    // std::pair<int, std::string> id_name = {123, "Joe"};
    // swap_pointed_to<int>(p, q);
    // result_type<decltype(it), int *> result = ...;
    // static_assert(not is_big_and_trivial<int>);

    // std::pair id_name = {123, "Joe"};
    // swap_pointed_to(p, q);
    // result_type<decltype(it), int *> result = ...;
    // static_assert(not is_big_and_trivial<int>);
}
