// Custom Deleters

// What if cleanup action is something other than calling delete ?

#include <cstdio>
#include <memory>

// FILE *fp = fopen("readme.txt", "r");
// fread(buffer, 1, N, fp);
// fclose(fp); // might be forgetten or skipped

// unique_ptr has an extra defaulted template parameter for the delete

template <typename T, typename Deleter = std::default_delete<T>>
class unique_ptr;

// Type `Deleter` must have an `operator()(T*)`
// make_unique doesn't support custom deleters
//     unique_ptr with custom deleter must be constructed directly

struct fclose_deleter {
    void operator()(FILE *fp) const {
        fclose(fp);
    }
};

// int main() {
//     using unique_FILE = std::unique_ptr<FILE, fclose_deleter>;
//     {
//         unique_FILE fp(fopen("readme.txt", "r"));
//         fread(buffer, 1, N, fp.get());
//     } // fclose called automatically
// }

// Custom deleter for shared_ptr is passed to constructor, where it is type erased

// int main() {
//     {
//         std::shared_ptr<FILE> fp(fopen("readme.txt", "r"), fclose_deleter {});
//         fread(buffer, 1, N, fp.get());
//         std::shared_ptr<FILE> fp2(fp);
//     } // fclose called automatically
// }
