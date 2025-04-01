# Overview

## Why is virtual useful

1. Requiring a specific interface.
2. Adding configurability to objects
3. Holding multiple different derived types with a shared base class in a single container. <!-- markdownlint-disable-line -->

## Why replace virtual

1. Less indirection.
2. Capture system properties more statically.
3. Greater flexibility in design.
4. Can improve performance.

## Desired properties

1. List of the types that might be stored.
2. Container that can hold many different types simultaneously.
3. Container that can hold multiple objects of a single type.

## Downsides

1. Increased translation unit size.
2. Potential increase to binary size.
3. May increase compile time.
4. May add complexity.
