// Helper Function as Sorting Criterion

#include <algorithm>
#include <string>
#include <vector>

class Person {
public:
    std::string firstname() const;
    std::string lastname() const;

    // ...
    friend bool operator<(Person const &p1, Person const &p2) // or op<=> (since C++20)
    {
        return p1.lastname() < p2.lastname()
               || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
    }

    Person(std::string f, std::string l) : first {std::move(f)}, last {std::move(l)} {}

private:
    std::string first;
    std::string last;
};

bool lessPerson(Person const &p1, Person const &p2) {
    // sort ascending to the last name or if equal ascending to the first name:
    return p1.lastname() < p2.lastname()
           || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
}

int main() {
    std::vector<Person> coll;
    coll.emplace_back("John", "Doe");
    coll.emplace_back("Jane", "Smith");
    coll.emplace_back("Alice", "Johnson");
    coll.emplace_back("Bob", "Doe");
    coll.emplace_back("Charlie", "Brown");

    // sort elements with operator <:
    std::sort(coll.begin(), coll.end()); // pass begin and end of elements to sort

    // sort elements with a special sorting criterion:
    std::sort(coll.begin(),
              coll.end(),  // elements to sort
              lessPerson); // sorting criterion
}

std::string Person::firstname() const {
    return this->first;
}

std::string Person::lastname() const {
    return this->last;
}
