// nested namespaces definitions

// since C++17:
namespace A::B::C {
    // ...
}

// equivalent to:
namespace A {
    namespace B {
        namespace C {}
    } // namespace B
} // namespace A
