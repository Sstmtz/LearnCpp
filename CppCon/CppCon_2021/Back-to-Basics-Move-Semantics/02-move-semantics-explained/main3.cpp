// Overloading on References

// read-only access
// - in parameter to read
// void foo(Type const &);
// - pass value without creating a copy
// - can bind to everthing

// write access
// - (in)out parameter
// void foo(Type &);
// - pass named entity to return a value
// - noly non-const named object (lvalues)

// move access
// - in parameter to adopt value
// void foo(Type &&);
// - pass value that is no longer needed
// - only objects without name or with move() (rvalues)

// ???
// void foo(Type const &&);
// - possible, but semantic contradiction
// - usually covered by `Type const&`

#include <string>
#include <utility>
#include <vector>

// example 1: declare variables
// std::vector<std::string> coll;
// // ...
// std::string const s = getData(); // Don't use const if you later move
// // ...
// coll.push_back(std::move(s)); // copies

// example 2: function parameters
// std::vector<std::string> coll;
// // ...
// void insert(std::string const &s) { // Don't use const if you later move
//     coll.push_back(std::move(s)); // copies
// }

// example 3: function return-type
// std::string const getValue(); // Don't use const when returning by value
// // ...
// std::vector<std::string> coll;
// // ...
// coll.push_back(getValue()); // copies
