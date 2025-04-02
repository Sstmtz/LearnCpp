#include <string>

// C++14: Return Type auto
//
// Let the compiler deduce the return type

template <typename T1, typename T2>
auto mymax(T1 a, T2 b) {
    return b < a ? a : b;
}

int main() {
    int         i = 42;
    std::string s {"hi"};

    // auto a1 = mymax(i, 0.7);         // OK: mymax<int, double>() => double(T2)
    // auto a2 = mymax(0.7, i);         // OK: mymax<double,int>() => double(T1)
    auto a1 = mymax(i, 0.7);         // OK: mymax<double,int>() => double(T1)
    auto a2 = mymax(0.7, i);         // OK: return type is double
    auto a3 = mymax<double>(i, 0.7); // OK: return type is double
    auto a4 = mymax<long>(0.7, i);   // return type is long(may convert 0.7 to 0)

    // auto s1 = mymax("hi", s);        // OK: mymax<const char*, std::string>() => std::string(T2)
    // auto s2 = mymax(s, "world");     // OK: mymax<std::string, const char*>() => std::string(T1)
    auto s1 = mymax("hi", s);    // OK: return type is std::string
    auto s2 = mymax(s, "world"); // OK: return type is std::string
}
