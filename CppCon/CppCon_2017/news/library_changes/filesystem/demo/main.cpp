#include <filesystem>
#include <fstream>
#include <string>

int main() {
    // before C++17 (Windows):
    std::wstring dir = L"\\sandbox";
    std::wstring p = dir + L"\\foobar.txt";
    std::wstring copy = p;
    copy += ".bak";
    CopyFile(p, copy, false);

    std::string    dir_copy = dir + ".bak";
    SHFILEOPSTRUCT s = {0};
    s.hwnd = someHwndFromSomewhere;
    s.hFunc = FO_COPY;
    s.fFlags = FOF_SILENT;
    s.pFrom = dir.c_str();
    s.pTo = dir_copy.c_str();
    SHFileOperation(&s);

    // since C++17:
    // use filesystem:
    std::filesystem::path dir = "/";
    dir /= "sandbox";
    std::filesystem::path p = dir / "foobar.txt";
    std::filesystem::path copy = p;
    copy += ".bak";
    std::filesystem::copy(p, copy);

    std::filesystem::path dir_copy = dir;
    dir_copy += ".bak";

    std::filesystem::copy(dir, dir_copy, std::filesystem::copy_options::recursive);
}
