#include <memory>
#include <type_traits>

// With what we now have, can we make this better / harder to use wrong?
[[nodiscard]] std::unique_ptr<Widget> make_widget(int widget_type);

// Depending on context, we might be able to use strongly typing to make our factory better:
template <typename WidgetType>
[[nodiscard]] WidgetType make_widget()
    requires(std::is_base_of_v<Widget, WidgetType>);
