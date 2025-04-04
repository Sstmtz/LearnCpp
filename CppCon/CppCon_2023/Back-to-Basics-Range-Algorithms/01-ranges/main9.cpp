
// Fun with the Simpsons (C++20)

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>

struct Person {
    std::string firstname;
    std::string lastname;
    int         age;
};

bool isChild(Person const &p) {
    if (p.age < 18) {
        return true;
    }
    return false;
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

    // std::ranges::partition(table, [](Person const &p) {
    //     return isSeniorCitizen(p);
    // });

    auto const pos = std::ranges::stable_partition(table, [](Person const &p) {
        return isSeniorCitizen(p);
    });

    // std::rotate(std::begin(table), pos, std::end(table)); // OK
    // std::rotate(std::begin(table), std::end(table), pos); // UB
    std::ranges::rotate(table, pos);

    // ...

    return EXIT_SUCCESS;
}

// 1. Easy to read
// 2. Easy to understand
// 3. Less Verbose
// 4. Easy to get right
// 5. Reusable
