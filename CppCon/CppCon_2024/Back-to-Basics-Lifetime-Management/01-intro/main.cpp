// C++ is a value-based language by default

// three phases:
// - construction
// - assignment
// - destruction

#include <string>
#include <vector>

{
    int i = 42; // construction
    i = 7;      // assignment
} // destruction

{
    std::string = "initial"; // construction
    s = "assigned";          // assignment
} // destruction

{
    std::vector v = {2, 4, 6, 8}; // construction
    v = {1, 2, 3, 4, 5};          // assignment
} // destruction

Gadget gadget1;
Gadget gadget2;

// even pointer are just value types
{
    Gadget *gadget = &gadget1; // construction
    gadget = &gadget2;         // assignment
} // destruction

// construction
// - default ctor: T()
// - custom ctor: T(A, B, C, ...)
// - copy ctor: T(T const&)
// - move ctor: T(T &&)
// assignment:
// - copy-assign: operator=(T const&)
// - move-assign: operator=(T &&)
// destruction:
// - destructor: ~T()
