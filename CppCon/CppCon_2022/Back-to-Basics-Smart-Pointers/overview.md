# Overview

## Raw Pointer

- Single object vs. array
  - Single: allocate with `new`, free with `delete`
  - Array: allocate with `new[]`, free with `delete[]`
  - Single: don't use `++p`, `--p` or `p[n]`
  - Array: `++p`, `--p` and `p[n]` are fine
- Owning vs. non-owning
  - Owner must free the memory when done
  - Non-owner must never free the memory
- Nullable vs. non-nullable
  - Some pointers can never be null
  - It would be nice if the type system helped enforce that
- The type system doesn't help
  - `T*` can be used for all combinations of these characteristics

## Smart Pointer

- Behaves like a pointer
  - ... at least one of the roles of a pointer
  - Points to an object
  - Can be dereferenced
- Add additional "smart"
  - Often limits behavior to certain of a pointer's possible roles
- "Smart" can be almost anything
  - Automatically release resources is most common
  - Enforce restrictions, e.g. don't allow `nullptr`
  - Extra safety checks
- Sometimes the smarts are only in the name
  - `gsl::owner<T>` is just a typedef of `T*`; it only has meaning for those reading the code

Non-owning pointer to a single object
Use a smart pointer for all owning pointers
Use a span type in place of non-owning pointers to arrays
    - C++20 `std::span` or `gsl::span`

## Unique_ptr vs. Shared_ptr

- Single owner: use `unique_ptr`
- Multiple owner: use `shared_ptr`
- Non-owning reference: use something else entirely
- When in doubt, prefer `unique_ptr`
    Easier to switch from `unique_ptr` to `shared_ptr` than the other way around

## Raw pointer vs. Smart pointer

- Raw pointers can fulfill lots of roles
  - Can't fully communicate the programmer's intent
- Smart pointers can be very powerful
  - Automatic tasks, especially cleanup
  - Extra checking
  - Limited API, to better express programmer's intent

## Standard vs. Custom Smart Pointers

- Standard C++ has two commonly used smart pointers
  - `unique_ptr` and `shared_ptr`
  - Use them whenever they fit your needs
- Don't limit yourself to standard smart pointers
  - If your framework has smart pointers, use them
  - Write your own if necessary

## Guidelines

- Use smart pointers to represent ownership
- Prefer `unique_ptr` over `shared_ptr`
- Use `make_unique` and `make_shared`
- Pass/return `unique_ptr` to transfer ownership between functions
