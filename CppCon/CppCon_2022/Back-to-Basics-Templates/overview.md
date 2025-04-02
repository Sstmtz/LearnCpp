# Overview

## Non-Type Template Parameter (NTTP) Types

- Supported types:
  - Types for constant integral values (`int`, `long`, `enum`, ...)
  - `std::nullptr_t` (the type of `nullptr`)
  - Pointers to globally visable objects/functions/members
  - Lvalue refereneces to objects or functions

- Not Supported are:
  - String literals (directly)
  - Classes

- Since C++20 Supported are:
  - Floating-point types (`float`, `double`, ...)
  - Data structures with public members
  - Lambdas
