# Overview

## Basic Move Support

- Guarantee for library objects
  - "Unless otherwise specified, ... moved-from objects shall be placed in a **valid but unspecified** state."
- Copy as Fallback
  - If no move semantics is provided, copy semantics is used
    - you can disable this fallback (Used by Move-Only Types such as `std::thread, streams, std::unique_ptr<>`)
- Default move operations are generated
  - Move constructor and move assignment operator
    - move members
    but only if this can't be a problem
    - Only if there is no user-declared special member function
      - No copy constructor
      - No assignment operator
      - No destructor
