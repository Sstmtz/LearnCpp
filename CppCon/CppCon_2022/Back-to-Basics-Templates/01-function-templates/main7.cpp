#include <iostream>
#include <string>

// C++98: Mutliple Template Parameters
//
// You can provide mutliple template parameters:

template <typename T1, typename T2>
void print(const T1 &val1, const T2 &val2) {
    std::cout << val1 << ' ' << val2 << '\n';
}

int main() {
    int i1 = 42, i2 = 77;
    print(i1, i2);    // OK: print<int,int>()
    print(0.7, 33.4); // OK: print<double, double>()
    print(i1, 0.7);   // OK: print<int, double>()

    std::string s {"hi"}, t {"world"};
    print(s, t);                   // OK: print<std::string, std::string>()
    print("hi", "world");          // OK: print<char[3], char[6]>()
    print("hi", s);                // OK: print<char[3], std::string>()

    print<double>(i1, i2);         // OK: print<double,int>
    print<double, double>(i1, i2); // OK: print<double,double>
}
