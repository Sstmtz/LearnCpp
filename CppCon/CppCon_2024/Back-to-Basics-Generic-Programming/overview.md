# Overview

## Define a Template

```cpp
template <template-parameters> declaration;
```

1. declaration can be
    - `class/struct`
    - `function`
    - `type alias`
    - `variable`
    - `concept`
2. template-parameter is
    - `class|typename identifier [=default-value]`
3. Template definition should be in a header file.

## Template Parameters

- Three kinds
  - Type template parameter
    - `class|typename identifier`
  - Non-type template parameter (NTTP)
    - `type|auto identifier`
  - Template template parameter
    - `template <template-parameters> class|typename identifier`

- Name is optional
  - Type template parameter
    - `class|typename [identifier]`
  - Non-type template parameter (NTTP)
    - `type|auto [identifier]`
  - Template template parameter
    - `template <template-parameters> class|typename [identifier]`

- Default value is optional
  - Type template parameter
    - `class|typename [identifier] [=default-value]`
  - Non-type template parameter (NTTP)
    - `type|auto [identifier] [=default-value]`
  - Template template parameter
    - `template <template-parameters> class|typename [identifier] [=default-value]`

- Variadic
  - Type template parameter
    - `class|typename ... [identifier]`
  - Non-type template parameter (NTTP)
    - `type|auto ... [identifier]`
  - Template template parameter
    - `template <template-parameters> class|typename ... [identifier]`

## Using a template

```cpp
template-name <template-argumnets>
```

- Template argument kind must match template parameter kind:
  - type
  - compile-time constant of correct type
  - template name

## Substitution vs. Instantiation

Substitution
  Substitute template arguments for template parameters
  Results in class declaration of function declaration
  Checks the correctness of the template arguments
Instantiation
  Full definition of the class of function or type alias or variable
  Happens after Substitution, only when full definition is needed
  Checks the correctness of the definition

## SFINAE

Substitution Failure Is Not An Error
A failure during Substitution does not fail compilation
Instead, the candidate is discarded
This feature is necessary for function templates and class template partial specializations to be useful

## Class Template Instantiation is a Type

```cpp
class-template-name <template-argumnets>
```

Results in a regular type
Each instantiation is a distinct and unrelated type

## No Function Template Arguments

Use function template like a regular function
Let the compiler deduce the arguments useless the function's API requires explicit template arguments

## Constraints

Requirements on a  template argument
Checked during substitution, not instantiation
Often make use of concepts and requires clauses

## KISS Principle

Keep It Simple and Straightforward
No fancy template metaprogramming or type-based metafunctions
Make it easy for your users

## Document Requirements

Document expectations for the template parameters
In code if possible via constraints
In documentation otherwise
Member functions can have additional requirements

## Specialization

Sometimes one instantiation of a class template should behave differently than the others
Define a class to be used in place of the normal instantiation
Specialization can have a completely different interface but that is usually a bad idea

- Specialization Allowed:
  - Class template: Yes
  - Variable template: Yes
  - Type alias template: No
  - Concept: No
  - Function template: see next section

## `typename` keyword

Compiler needs help parsing template definition
Keyword `typename` must precede any qualified type name that depends on a template parameter.

```cpp
A * B(C(D));
// Expression statement:
//   multiply A and B(C(D))
A* B = C(D);
// Variable definition
//   B is a variable of type pointer-to-A with initial value C(D) 
A* B(C(*fp)(D arg));
// Function declaration
// B is a function with parameter pointer-to-(function with parameter D returning C) returning pointer-to-A
```

## Function Template Specialization

- What is allowed:
  - Full specialization of non-member function templates
- What is not allowed:
  - Partial specialization of non-member function templates
  - Any specialization of member function templates

## Summary

- Define templates in header files
- Substitution checks the declaration and template arguments
- Instantiation checks the entire definition
- SFINAE: Substitution Failure Is Not An Error
- Let the compiler deduce arguments for a function template
- Constrain your template parameters
- Keep it simple
