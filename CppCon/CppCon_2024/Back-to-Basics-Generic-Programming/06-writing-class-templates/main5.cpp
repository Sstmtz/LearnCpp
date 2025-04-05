
// Type Alias Specialization Workaround

template <class T>
struct remove_pointer {
    using type = T;
};

template <class T>
struct remove_pointer<T *> {
    using type = T;
};

template <class T>
using remove_pointer_t = typename remove_pointer<T>::type;

int main() {
    return 0;
}
