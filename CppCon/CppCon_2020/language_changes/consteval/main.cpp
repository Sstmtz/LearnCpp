constexpr auto InchToMm(double inch) {
    return inch * 25.4;
}

consteval auto InchToMm2(double inch) {
    return inch * 25.4;
}

int main() {
    double const const_inch {6};
    auto const   mm1 {InchToMm(const_inch)}; // ok, run at compile time

    double     dynamic_inch {6};
    auto const mm2 {InchToMm(dynamic_inch)}; // ok, run at run time

    double const const_inch2 {6};
    auto const   mm3 {InchToMm2(const_inch2)}; // ok, run at compile time

    // double dynamic_inch2{6};
    // auto const mm4{InchToMm2(dynamic_inch2)}; // compile error
}
