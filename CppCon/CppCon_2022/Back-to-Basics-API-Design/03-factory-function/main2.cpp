#include <cstdio>
#include <filesystem>
#include <memory>
#include <string_view>

// The Humble `fopen` Function
FILE *fopen(char const *pathname, char const *mode);

// Easy or Hard to use wrong? Why?
// - How is error handling done?
// - What happens if we drop the return value?
// - What is the format for `mode`?
// - What happens if I call `fopen("W", "/my/file/path")`?
// - What happens if I call `fopen("my/file/path", 0)`?

using FilePtr = std::unique_ptr<FILE, decltype([](FILE *f) {
                                    fclose(f);
                                })>;
[[nodiscard]] FilePtr fopen(char const *pathname, char const *mode);

// Avoid easily swappable parameters:
[[nodiscard]] FilePtr fopen(std::filesystem::path const &path, std::string_view mode);

// Unfortunately this still compiles:
auto file = fopen("rw+", "/my/file");

// Assuming std::filesystem::path and std::string_view are the most correct
// for this use case, can we make this better?
void fopen(auto const &, auto const &) = delete;
