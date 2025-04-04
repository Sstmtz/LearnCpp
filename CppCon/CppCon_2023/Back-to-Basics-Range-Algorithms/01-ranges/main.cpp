
// Fun with the Simpsons (C++11)

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
    // (6. This comment is a clear indication that something is wrong)
    if (std::begin(table) == std::end(table)) {
        std::cout << "Empty table, no youngest person!\n";
    } else {
        auto smallest = std::begin(table);

        for (auto pos = std::begin(table) + 1; pos != std::end(table); ++pos) {
            if (pos->age < smallest->age) {
                smallest = pos;
            }
        }
        std::cout << "Youngest person = " << smallest->firstname << ' ' << smallest->lastname << '\n';
    }

    return EXIT_SUCCESS;
}

// 1. Hard to read
// 2. Hard to understand
// 3. Verbose
// 4. Easy to get wrong
// 5. Not reusable
