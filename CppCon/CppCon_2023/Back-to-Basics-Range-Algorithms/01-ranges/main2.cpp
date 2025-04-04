
// Introducing std::min_element() (C++11)

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct Person {
    std::string firstname;
    std::string lastname;
    int         age;
};

int main() {
    std::vector<Person> table = {
      Person {     "Homer",    "Simpson",  38},
      Person {     "Marge",    "Simpson",  34},
      Person {      "Bart",    "Simpson",  10},
      Person {      "Lisa",    "Simpson",   8},
      Person {    "Maggie",    "Simpson",   1},
      Person {      "Hans",    "Moleman",  33},
      Person {     "Ralph",     "Wiggum",   8},
      Person {  "Milhouse", "Van Houten",  10},
      Person {       "Ned",   "Flanders",  60},
      Person {      "Jeff",  "Albertson",  45},
      Person {"Montgomery",      "Burns", 104},
      /*many more Simpsons characters */
    };

    // Find the youngest person
    auto const pos = std::min_element(std::begin(table), std::end(table), [](Person const &lhs, Person const &rhs) {
        return lhs.age < rhs.age;
    });

    if (pos != std::end(table)) {

        std::cout << "Youngest person = " << pos->firstname << ' ' << pos->lastname << '\n';
    }

    return EXIT_SUCCESS;
}

// 1. Easy to read
// 2. Easy to understand
// 3. Less Verbose
// 4. Easy to get right
// 5. Reusable
