# Overview

## Concepts Terminology

- Requirements
  - Expressions to specify a restriction with `requires{...}`
    - Operations that have to be valid
    - Types that have to be defined/returned

- Concepts
  - Names for one or more Requirements

- Constraints
  - Restriction for the availability/usability of generic code
  - Specified as
    - `requires clauses` of concepts or ad-hoc requirements
    - `Type constraints` (concepts applied to template parameters or auto)

- No code is generated
  - Code is evaluated only to decide whether/what to compile

## Subsumptions of Standard Concepts (extract)

[Click to jump](https://youtu.be/jzwqTi7n-rg?t=2678)

## Where Concepts can be used

1. Concepts can be used for
    - Function templates
    - Class templates
        - Including their member functions
    - Alias templates
    - Variable templates
    - Non-type template parameters
2. Concepts cannot be used for concepts
