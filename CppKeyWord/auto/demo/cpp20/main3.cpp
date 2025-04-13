#include <type_traits>

// Abbreviated function template
//
// When placeholder types (either `auto` or `Concept auto`) appear in the parameter list of a
// function declaration or of a function template declaration, the declaration declares a function
// template, and one invented template parameter for each placeholder is appended to the template
// parameter list:

// Concept that checks if a type is an integral type
template <typename T>
concept Integral = std::is_integral_v<T>;

// Concept that checks if a type is a floating-point type
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

// Concept that checks if a type is a pointer type
template <typename T>
concept Pointer = std::is_pointer_v<T>;

// Concept that checks if a type is a reference type
template <typename T>
concept Reference = std::is_reference_v<T>;

void f1(auto);                  // same as template<class T> void f1(T);

void f2(Integral auto);         // same as template<Integral T> void f2(T);

void f3(FloatingPoint auto...); // same as template<FloatingPoint... Ts> void f3(Ts...);

void f4(Pointer auto const *,
        Reference auto &); // same as template<Pointer T, Reference U> void f4(const T*, U&);

template <class T, Integral U>
void g(T x,
       U y,
       Integral auto z); // same as template<class T, Integral U, Integral W> void g(T x, U y, W z);

int main() {
    return 0;
}
