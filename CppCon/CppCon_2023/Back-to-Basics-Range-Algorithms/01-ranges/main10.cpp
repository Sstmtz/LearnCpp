
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

    // Sum up the age of all persons
    int total_age = 0;
    for (auto const &person : table) {
        total_age += person.age;
    }
    std::cout << "Total age = " << total_age << '\n';

    // ...

    return EXIT_SUCCESS;
}
