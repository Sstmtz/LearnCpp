// 1. No Uniform Initialization in C++03

// We can think of C++03 as having three kinds of types to consider:
// - Scalars
// - Aggregates (e.g., arrays and classes with no user-provided constructors)
// - Classes with user-provided constructors

// No form of initialization works for all three kinds:
// - Scalars and classes with user-provided constructors didn't support brace initialization.
// - Aggregates didn't support direct-initialization.
