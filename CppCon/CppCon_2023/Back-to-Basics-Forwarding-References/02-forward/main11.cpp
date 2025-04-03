
// Move Semantics with T&&

#include <type_traits>
#include <vector>

// template <typename T>
// void foo(T &&);
//
// int main() {
//     std::vector       obj = {1, 2, 3};
//     std::vector const cobj = {1, 2, 3};
//
//     foo(obj);                   // lvalue -> should not compile
//     foo(cobj);                  // lvalue -> should not compile
//     foo(std::move(obj));        // rvalue -> should compile
//     foo(std::move(cobj));       // rvalue -> should compile
//     foo(std::vector {1, 2, 3}); // rvalue -> should compile
//
//     foo(obj);                   // foo<std::vector<int>&>(std::vector<int>&)
//     foo(cobj);                  // foo<const std::vector<int>&>(const std::vector<int>&)
//     foo(std::move(obj));        // foo<std::vector<int>>(std::vector<int>&&)
//     foo(std::move(cobj));       // foo<const std::vector<int>>(const std::vector<int>&&)
//     foo(std::vector {1, 2, 3}); // foo<std::vector<int>>(std::vector<int>&&)
// }

// std::is_lvalue_reference_v<T> is not enough here as someone may call the
// function with an explicit template parameter and not depend on a function
// template parameter deduction (i.e. foo<std::vector<int>&&>(v))
template <typename T>
    requires(! std::is_lvalue_reference_v<T>)
void foo(T &&);

int main() {
    std::vector       obj = {1, 2, 3};
    std::vector const cobj = {1, 2, 3};

    foo(obj);                   // ERROR
    foo(cobj);                  // ERROR
    foo(std::move(obj));        // OK
    foo(std::move(cobj));       // OK
    foo(std::vector {1, 2, 3}); // OK
}
