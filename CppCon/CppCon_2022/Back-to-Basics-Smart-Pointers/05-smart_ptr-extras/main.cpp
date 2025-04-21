// Casts

// To have share_ptrs of different types that manage the same object
// dynamic_pointer_cast, static_pointer_cast, const_pointer_cast, reinterpret_pointer_cast

#include <memory>

int main() {
    std::shared_ptr<WidgetBase> p = create_widget(inputs);
    std::shared_ptr<BlueWidget> b = std::dynamic_pointer_cast<BlueWidget>(p);
    if (b) {
        b->do_something_blue();
    }
}
