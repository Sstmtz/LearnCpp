// Preventing Narrowing Conversions

// The first difference from C++03 forms of initialization is that braced
// initialization prohibits narrowing conversions...

int dtoi1 = 12.3; // OK
int dtoi2 {12.3}; // ERROR: not narrowing allowed

int i = 12;
char itoc1 {i};  // ERROR: not narrowing allowed
float itof1 {i}; // ERROR: not narrowing allowed

// ...unless the initializer is a constant expressoion and the compiler can verify that
// there will be no loss of information.

constexpr int ci = 12;
char itoc2 {ci}; // OK if 12 fits in a char
float itof1 {s}; // OK if 12 fits int a float

// Intentional Narrowing Conversions

// Sometimes, you might need to use a narrowing conversion during initialization

// If so, consider using an explicit cast to show that it's intentional:

int i = 12;
char itoc1 {i};                    // ERROR
char itoc2 {static_cast<char>(i)}; // explicit conversion

// Although narrowing conversions are allowed on assignment, using an explicit cast makes it clear
// that it's intentional:

itoc1 = i;                    // intentional or accidental ?
itoc2 = static_cast<char>(i); // clearly intentional
