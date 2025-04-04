# Overview

## `[[nodiscard]]` Summary

- Used to indicate when it is an error to ignore a return value from a function.
- Can be applied to constructors as of C++20.
- Can have a message to explain the error `[[nodiscard("Lock objects should never be discarded")]]`.
- Should be used extensively. Any non-mutating (getter/accessor/`const`) function should be `[[nodiscard]]`.
  - cos() `[[nodiscard]]`
  - vector::insert() `[[nodiscard]]`
- Can be checked / enforced with static analysis.

## Never Return a Raw Pointer

- It simply raises too many questions. Who owns it? Who deletes it? Is it a singleton global?
- Consider `owning_ptr`, `non_owning_ptr` or some kind of wrapper to document intent, if you must.

## Consistent Error Handling

- Use one consistent method of reporting errors in your library.
- Strongly avoid out-of-band error reporting (`get_last_error` or `errno`)
- Make errors impossible to ignore (no returning an error code!)
- Never use `std::optional<>` to indicate an error condition. (it does not convey a reason, and the reason becomes out of bound)
- Consider `std::expected<>` (C++23) or similar.

## Avoid Easily Swappable Parameters

- Two (or more) parameters beside each other of the same type are easy to swap.
- clang-tidy has `[bugprone-easily-swappable-parameters]`.

## Avoid Implicit Conversions / Use Strong Types

- `std::filesystem::path` and `std::string_view` appear to be strongly typed but are not.
- Implicit conversions between `const char *`, `string`, `string_view`, and `path` break type safety.
- Conversion operators and single parameters constructors (including variadic and ones with default parameters) should be `explicit`.

## `=delete` Problematic Overloads

- Any function can be `=delete`d.
- If you `=delete` a template, it will become the match for any non-exact parameters, and prevent implicit conversions.

## Summary

- Try to use your API incorrectly.
- Use better naming.
- Use `[[nodiscard]]` (with reasons) liberally.
- Never return a raw pointer.
- Use `noexcept` to help indicate the type of error handling.
- Provide consistent, impossible to ignore, in-band error handling.
- Use stronger types and avoid default conversions.
- (Sparingly) delete problematic overloads / prevent conversions.
- Avoid passing pointers (only to be used for single/optional objects).
- Avoid passing smart pointers.
- Limit your API as much as possible.
- Fuzz your API.
