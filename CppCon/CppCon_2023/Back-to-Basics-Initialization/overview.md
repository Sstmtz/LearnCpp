# Overview

## Initialization Rules from C

- `Scalars` are simple values such as:
  - integers
  - characters
  - floating-point values
  - enumerations
  - pointers
- `Aggregates` are objects that are made up of smaller pieces, such as:
  - structures
  - arrays
- Unions aren't technically aggregates in C
  - However, some unions are aggregates in C++

- For an object without explicit initializer:
  - If the object has **static** or **thread** storage duration (i.e. declared `static`, `thread_local`, or at `namespace` scope), it's **zero-initialized**  
    - That is, initialized as if with the value 0.
    - For aggregates, every field/element is initialized as if with 0.
    - A pointer is always initialized to null, even on platforms where the null pointer doesn't strictly have value 0.
  - Otherwise, the object is left uninitialized (a.k.a. it has an **indeterminate value**).
    - Accessing an object with an indeterminate value often produces undefined behavior.

## On The Origins of Constructors

- When using aggregate-initialization, the user has full control over how the object is initialized.
- In other words, if `demo_str` is an aggregate, it's up to the user to understand its invariants and preserve them.
  - The author of `demo_str` can't do much to help.
- By contrast, the author of `demo_str` decides which constructors `demo_str` will provide an what they will do.
- Thus, the author can ensure that all of the constructors respect the class invariants.
- This led to an important rule in C++:
  - If a class C has any(user-provided) constructors, then C is not an aggregate and doesn't support aggregate-initialization.

## Definition of an Aggregate

- More specifically, in C++03, a class type is an aggregate if it has:
  - no user-declared constructors
  - no private or protected non-static data members
  - no base classes
  - no virtual functions
- More recent versions of a language have relaxed the requirements, so that a few more class types are considered aggregates...
- In C++20, a class type is an aggregate if it has:
  - no user-declared or inherited constructors
  - no private or protected direct non-static data members
  - no virtual, private or protected base classes
  - no virtual functions

## Value-Initialization

- What it means to `value-initialize` an object of type `T` depends a little on the properties of `T`:
  - If `T` has a user-provided default constructor, call it.
  - If `T` is an array, value-initialize all of its elements.
  - If `T` is a scalar, zero-initialize it.
  - Otherwise, the initialization is valid only if `T` has no user-provided constructors
  - For each data member of `T`:
    - Zero-initialize the data member.
    - Then, default-initialize the data member (i.e., call the default constructor)

## Areas for Improvement in C++03

- While C++03 provided a lot of good options for initializing objects, there were some significant annoyances:
  1. no uniform initialization synatx
  2. narrowing conversions
  3. roundabout value-initialization
  4. no ability to initialize an STL container like an array

## Takeaways

- The initialization rules evolved as they did to avoid breaking existing code as much as possible.
- There are many forms of initialization
  - The members of an object might be initialized using a different form than the object itself.
- Braced initialization prevents narrowing conversions.
- Decide up-front whether a type should have a `std::initializer_list` constructor.
  - Avoid adding or removing a `std::initializer_list` constructor to/from an existing type.
