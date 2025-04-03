# Overview

## Summary

- Use `const MyType&` when a read access is only needed
  - binds to everything and cheap to instantiate
- Use both `const MyType&` and `MyType&&` for sinks where it it not too expensive
  - consider `MyType` for expensive scenarios
- Use `T&&` to forward the argument
  - beware of single-argument constructors
  - remember that it binds to everything not just the type you need
  - remember that it is not a rvalue reference
- Use `decltype(auto` as function return type to perfectly return the result of another function's invocation
- Use `auto&&` to store a forwarding reference for later forwarding
  - also useful in range-for loops in generic context
