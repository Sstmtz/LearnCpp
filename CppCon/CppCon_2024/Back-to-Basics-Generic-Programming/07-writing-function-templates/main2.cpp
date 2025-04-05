
// Deducible Template Parameters

// Make all template parameter deducible Except when you can't

template <class Result, class Source>
Result my_fancy_cast(Source const &src) {
    // ...
}

my_fancy_cast<Widget>(parts.getFidget());
