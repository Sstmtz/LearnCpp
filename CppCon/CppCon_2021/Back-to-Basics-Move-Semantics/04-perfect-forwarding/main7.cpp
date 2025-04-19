// auto&& as Universal/Forwarding Reference

// - Reference that
//   - can universal refer
//     - to temporary objects and objects marked with move() (rvalues)
//     - to named objects (lvalues)
//   - keeps it non-constness
//   - is useful for perfect forwarding

#include <string>
std::string returnTmpString();
std::string const &returnConstStringRef();
std::string s {"some lvalue"};

// const auto& can refer to everything, but const
auto const &s1 = s;                      // OK, s1 is const
auto const &s2 = returnTmpString();      // OK, s2 is const
auto const &s3 = returnConstStringRef(); // OK, s3 is const

// auto&& cannot refer to everything
auto &s4 = s;                      // OK, s4 is non-const
auto &s5 = returnTmpString();      // ERROR: cannot bind non-const lvalue reference to rvalue
auto &s6 = returnConstStringRef(); // OK, s6 is const

// auto&& can refer to everything and keeps non-constness
auto &&s7 = s;                      // OK, s7 is non-const
auto &&s8 = returnTmpString();      // OK, s8 is non-const
auto &&s9 = returnConstStringRef(); // OK, s9 is const
