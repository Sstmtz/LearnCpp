# Overview

## Summary

- Key role of C++
  - Glue between ranges and algorithms
- Pure abstraction
  - Everything that behaves like an iterator is an iterator
- Different categories with different abilities
- Do not know their ranges (in general)
  - Don't know where the end is
  - Cannot insert/remove
- Use iterator with care
  - Referenced range has to be valid
  - Don't compare iterators not referring to the same range
- Iterators of C++2x filter views cache begin
  - Results in break idioms and unexpected behavior
