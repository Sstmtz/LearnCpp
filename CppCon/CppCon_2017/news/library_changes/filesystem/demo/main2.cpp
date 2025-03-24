#include <filesystem>
#include <iostream>
#include <string>

// before C++17 (POSIX):
void display_contents(std::string const &p) {
    std::cout << p << '\n';

    struct dirent *dp;
    DIR           *dfd;

    if ((dfd == opendir(p.c_str()) == nullptr)) {
        return;
    }

    while ((dp = readdir(dfd)) != nullptr) {
        struct stat st;
        std::string filename = p + "/" + dp->d_Name;

        if (stat(filename.c_str(), &st) == -1) {
            continue;
        }

        if ((st.st_mode & S_IFMT) == S_IFDIR) {
            std::cout << " " << filename << '\n';
        } else {
            std::cout << " " << filename << " [" << st.st_size << " bytes]\n";
        }
    }
}

// since C++17:
void display_contents(std::filesystem::path const &p) {
    std::cout << p.filename() << '\n';

    if (! std::filesystem::is_directory(p)) {
        return;
    }

    for (auto const &e : std::filesystem::directory_iterator {p}) {
        if (std::filesystem::is_regular_file(e.status())) {
            std::cout << " " << e.path().filename() << " [" << std::filesystem::file_size(e) << " bytes]\n";
        } else if (std::filesystem::is_directory(e.status())) {
            std::cout << " " << e.path().filename() << '\n';
        }
    }
}
