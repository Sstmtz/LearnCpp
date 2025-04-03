#include <concepts>
#include <string>
#include <type_traits>
#include <utility>

using namespace std::string_literals;

// Sinks: The most efficient overloads set
class MyClass {
    std::string txt_;

public:
    explicit MyClass(std::string const &txt) : txt_(txt) {}

    explicit MyClass(std::string &&txt) : txt_(std::move(txt)) {}
};

// Sinks: Scaling Problems
class MyClass2 {
    std::string txt1_;
    std::string txt2_;

public:
    explicit MyClass2(std::string const &txt1, std::string const &txt2) : txt1_(txt1), txt2_(txt2) {}

    explicit MyClass2(std::string &&txt1, std::string &&txt2) : txt1_(std::move(txt1)), txt2_(std::move(txt2)) {}

    explicit MyClass2(std::string const &txt1, std::string &&txt2) : txt1_(txt1), txt2_(std::move(txt2)) {}

    explicit MyClass2(std::string &&txt1, std::string const &txt2) : txt1_(std::move(txt1)), txt2_(txt2) {}
};

// Sinks: Good compromise

class MyClass3 {
    std::string txt1_;
    std::string txt2_;

public:
    MyClass3(std::string txt1, std::string txt2) : txt1_(std::move(txt1)), txt2_(std::move(txt2)) {}
};

// Add one move construction and destruction of a moved from object operations for lvalues and xvalues

// Sinks: Perfect Forwarding to the rescue
class MyClass4 {
    std::string txt1_;
    std::string txt2_;

public:
    template <typename T, typename U>
    MyClass4(T &&txt1, U &&txt2) : txt1_(std::forward<T>(txt1))
                                 , txt2_(std::forward<U>(txt2)) {}
};

// MyClass4 c1(42, 3.14); // ERROR

// Sinks: Constrainting a forwarding reference (native approach)
class MyClass5 {
    std::string txt1_;
    std::string txt2_;

public:
    template <std::same_as<std::string> T, std::same_as<std::string> U>
    MyClass5(T &&txt1, U &&txt2) : txt1_(std::forward<T>(txt1))
                                 , txt2_(std::forward<U>(txt2)) {}
};

// MyClass5    c1(42, 3.14);       // ERROR
// MyClass5    c2("abc"s, "def"s); // OK
// std::string txt = "abc";
// MyClass5    c3(txt, txt);       // ERROR

// Sinks: Constrainting a forwarding reference
class MyClass6 {
    std::string txt1_;
    std::string txt2_;

public:
    template <typename T, typename U>
        requires std::same_as<std::remove_cvref_t<T>, std::string> && std::same_as<std::remove_cvref_t<U>, std::string>
    MyClass6(T &&txt1, U &&txt2) : txt1_(std::forward<T>(txt1))
                                 , txt2_(std::forward<U>(txt2)) {}
};

// MyClass6    c1(42, 3.14);       // ERROR
// MyClass6    c2("abc"s, "def"s); // OK
// std::string txt = "abc";
// MyClass6    c3(txt, txt);       // OK
// MyClass6    c4("abc", "def");   // ERROR

// Sinks: Constrainting a forwarding reference
class MyClass7 {
    std::string txt1_;
    std::string txt2_;

public:
    template <std::convertible_to<std::string> T, std::convertible_to<std::string> U>
    // Use std::convertible_from to allow explicit conversions as well
    MyClass7(T &&txt1, U &&txt2) : txt1_(std::forward<T>(txt1))
                                 , txt2_(std::forward<U>(txt2)) {}
};

// MyClass7    c1(42, 3.14);       // ERROR
// MyClass7    c2("abc"s, "def"s); // OK
// std::string txt = "abc";
// MyClass7    c3(txt, txt);       // OK
// MyClass7    c4("abc", "def");   // OK
