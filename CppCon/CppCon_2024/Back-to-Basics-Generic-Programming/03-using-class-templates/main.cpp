
// Instantiations are Unrelated Types

struct A {};

struct B {};

template <class T>
struct D {};

int main() {
    A  a;
    B  b = a;   // ERROR: conversion from 'A' to non-scalar type 'B' requested
    B *bp = &a; // ERROR: cannot convert 'A*' to 'B*' in initialization

    D<int>     di;
    D<double>  dd = di;       // ERROR: conversion from 'D<int>' to non-scalar type 'D<double>' requested
    D<double> *ddp = &di;     // ERROR: cannot convert 'D<int>*' to 'D<double>*' in initialization

    D<int const>  dci = di;   // ERROR: conversion from 'D<int>' to non-scalar type 'D<const int>' requested
    D<int const> *dcip = &di; // ERROR: cannot convert 'D<int>*' to 'D<const int>*' in initialization
}
