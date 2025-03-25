
// We already have haterogeneous `lookup` for associative containers
// 1. avoids creating temporary objects of type key during lookups
// E.g: lookup with C-Style string fpr container with std::string as key type

#include <set>
#include <string>
std::set<std::string> s;
// ...
auto iter = s.find("Hello");

// C++23 adds haterogeneous erase() and extract()
