
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

struct Person {
    std::string firstname;
    std::string lastname;
    int         age;
};

std::ostream &operator<<(std::ostream &os, Person const &person) {
    /*....*/
    return os;
}

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

    std::copy(std::begin(table), std::end(table), std::ostream_iterator<Person>(std::cout, "\n"));

    std::for_each(std::begin(table), std::end(table), [](Person const &p) {
        std::cout << p << '\n';
    });

    for (auto const &p : table) {
        std::cout << p << '\n';
    }
}
