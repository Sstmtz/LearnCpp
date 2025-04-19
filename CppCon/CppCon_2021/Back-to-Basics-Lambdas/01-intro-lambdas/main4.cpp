// Combining Lambdas with Standard Algorithms
// Combining Lambdas with Standard Range Algorithms (C++20)

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print(std::vector<T> const &vec) {
    for (auto const &v : vec) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::string> coll {
      "Here", "are", "some", "cities", "Berlin", "LA", "London", "Cologne"};

    std::sort(coll.begin(), coll.end());
    print(coll);

    std::sort(coll.begin(),
              coll.end(),                                        // range to sort
              [](std::string const &s1, std::string const &s2) { // sort criterion
                  // std::lexicographical_compare is used for comparing elements of two
                  // containers
                  return std::lexicographical_compare(s1.begin(),
                                                      s1.end(),              // string as 1st range
                                                      s2.begin(),
                                                      s2.end(),              // string as 2nd range
                                                      [](char c1, char c2) { // compare criterion
                                                          return std::toupper(c1)
                                                                 < std::toupper(c2);
                                                      });
              });
    print(coll);

    // since C++20:

    std::ranges::sort(coll);
    print(coll);

    std::ranges::sort(coll,                                              // range to sort
                      [](std::string const &s1, std::string const &s2) { // sort criterion
                          auto toUpper = [](char c) {
                              return std::toupper(c);
                          };
                          return std::ranges::lexicographical_compare(
                              s1,           // string as 1st range
                              s2,           // string as 2nd range
                              std::less {}, // compare criterion
                              toUpper,      // projection for s1 elem
                              toUpper);     // projection for s2 elem
                      });
    print(coll);
}
