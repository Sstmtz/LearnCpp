#include <span>
#include <spanstream>

// Allows to use stream operations on external buffers

int main() {
    // E.g. Input:
    char             data[] = "11 22";
    std::ispanstream s {std::span<char> {data}};
    int              a, b;
    s >> a >> b;

    // E.g. Output:
    char             data2[32];
    std::ospanstream s2 {std::span<char> {data2}};
    s2 << 22 << 11;
}
