#include <string>

struct Data {
    int         m_a {0};
    std::string m_str;
};

int main() {
    // Designated Initializers
    Data d {.m_str = "Hello World!"};
}
