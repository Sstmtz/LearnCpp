// Lambdas as Sorting Criterion (since C++11)

#include <algorithm>
#include <string>
#include <vector>

class Person {
public:
    std::string firstname() const;
    std::string lastname() const;
    // ...
    std::string getCustNo() const; // return customer number

    Person(std::string f, std::string l, std::string No)
        : first {std::move(f)}
        , last {std::move(l)}
        , No {std::move(No)} {}

private:
    std::string first;
    std::string last;
    std::string No;
};

int main() {
    std::vector<Person> coll;

    coll.emplace_back("John", "Doe", "C001");
    coll.emplace_back("Jane", "Smith", "C002");
    coll.emplace_back("Alice", "Johnson", "C003");
    coll.emplace_back("Bob", "Doe", "C004");
    coll.emplace_back("Charlie", "Brown", "C005");

    // sort according to the name:
    std::sort(coll.begin(),
              coll.end(),                              // elements to sort
              [](Person const &p1, Person const &p2) { // sorting criterion
                  // sort ascending to the last name or if equal ascending to the first name:
                  return p1.lastname() < p2.lastname()
                         || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
              });

    // sort according to the customer number:
    std::sort(coll.begin(),
              coll.end(),                              // elements to sort
              [](Person const &p1, Person const &p2) { // sorting criterion
                  return p1.getCustNo() < p2.getCustNo();
              });
}

std::string Person::firstname() const {
    return this->first;
}

std::string Person::lastname() const {
    return this->last;
}

std::string Person::getCustNo() const {
    return this->No;
}
