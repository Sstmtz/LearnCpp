# Overview

## C++ Parallel Algorithms Summary

- Use C++ standard parallel algorithms when appropriate
- Use the right algorithm for the task
- Make sure your code is thread safe with no data races

## `std::thread` Low-level tool

- Don't use std::thread directly
- Use a threading library or other task management system
- Similar characteristics to std::thread:
  - A way to start a thread or start work concurrently
  - A way to wait for the task to complete, or at least check for completion
- Might have a way to return a value

## Data Races

Definition

1. Two or more threads access the same memory
2. At least one access is a write
3. The threads do not synchronize with each other
A data race is undefined behavior (UB)

## Conclusion

1. Concurrency is hard
2. Use parallel algorithms when appropriate
3. Avoid data races at all costs
    - Share less data
    - Use mutexes and Lock guards
