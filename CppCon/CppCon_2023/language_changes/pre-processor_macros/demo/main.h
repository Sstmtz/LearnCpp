// New preprocessor directives
// #elifdef, #elifndef and #warning

// Existing:
// `#ifdef id` shorted for `#if defined(id)`
// `#ifndef id` shorted for `#if !defined(id)`
// C++23 adds:
// `#elifdef id` shorted for `#elif defined(id)`
// `#elifndef id` shorted for `#elif !defined(id)`
// `#warning "This is a warning message"`
