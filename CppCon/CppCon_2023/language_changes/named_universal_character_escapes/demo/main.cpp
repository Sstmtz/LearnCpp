#include <iostream>
#include <locale>

// Use Unicode assigned names instead of code point values
// E.g:

// before C++23:
// UTF-32 character literal {LATIN CAPITAL LETTER A WITH MACRON}
auto a {U'\u0100'};
// UTF-32 string literal {LATIN CAPITAL LETTER A WITH MACRON}{COMBINING GRAVE ACCENT}
auto b {u8"\u0100\u0300"};

// since C++23:
auto a_ {U'\N{LATIN CAPITAL LETTER A WITH MACRON}'};
auto b_ {u8"\N{LATIN CAPITAL LETTER A WITH MACRON}\N{COMBINING GRAVE ACCENT}"};

int main() {
    // Set the locale to support Unicode
    std::locale::global(std::locale("en_US.UTF-8"));
}
