// since C++20, support for atomic shared pointer: atomic<shared_ptr<T>>
// and some global non-member atomic operations(e.g. std::atomic_load(), atomic_store()) have been deprecated.

#include <atomic> // for std::atomic<std::shared_ptr<T>>
#include <memory>

// #include <experimental/atmoic> // for std::experimental::atomic_shared_ptr<T>

template <typename T>
class concurrent_stack {
    struct Node {
        T                     t;
        std::shared_ptr<Node> next;
    };

    std::atomic<std::shared_ptr<Node>> head;
    // in C++11, remove "atomic_" and special functions every time you touch head
    // std::experimental::atomic_shared_ptr<Node> head;

public:
    class reference {
        std::shared_ptr<Node> p;
        // <snip>
    };

    auto find(T t) const {
        auto p = head.load();
        // C++11: auto p = atomic_load(&head)
        while (p && p->t != t) {
            p = p->next;
            return reference(move(p));
        }
    }

    auto front() const {
        return reference(head);
        // C++11: atomic_load(&head)
    }

    void push_front(T t) {
        auto p = std::make_shared<Node>();
        p->t = t;
        p->next = head;
        while (! head.compare_exchange_weak(p->next, p)) {
            // C++11: atmoic_compare_exchange_weak(&head, &p->next, p);
            // ...
        }
    }

    void pop_front() {
        auto p = head.load();
        while (p && ! head.compare_exchange_weak(p, p->next)) {
            // C++11: atmoic_compare_exchange_weak(&head, &p, p->next);
            // ...
        }
    }
};

int main() {
    return 0;
}
