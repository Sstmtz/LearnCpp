// Vacuous Initialization

// Just like in C, scalar object with no initializer is left uninitialized (a.k.a., has an
// indeterminate value)

int x; // uninitialized

// However, C++ still refers to `x` as default-initialized to describe when x's lifetime begins

// This creates some confusing terms in the Standard:
// - In some places, the Standard refers to x as uninitialized
// - In others, the Standard refers to this do-nothing form of initialization as vacuous
//   initialization.
