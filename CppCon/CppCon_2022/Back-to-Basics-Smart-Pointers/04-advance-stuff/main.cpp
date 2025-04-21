// WEAK_PTR

// A non-owning reference to a shared_ptr-managed object

// Knows when the lifetime of the managed object ends

#include <cstdio>
#include <memory>

int main() {
    std::weak_ptr<int> w;
    {
        auto s = std::make_shared<int>(42);
        w = s;
        std::shared_ptr<int> t = w.lock();
        if (t) {
            printf("%d\n", *t);
        }
    }
    std::shared_ptr<int> u = w.lock();
    if (! u) {
        printf("empty\n");
    }
}
