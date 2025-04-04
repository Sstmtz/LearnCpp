#include <memory>

enum class WidgetType {
    Slider = 0,
    Button = 1
};

Widget *make_widget(int widget_type);

// Easy or Hard to use wrong?
// - What happens if we ignore the return value?
// - What is the possible range of input values?

[[nodiscard]] std::unique_ptr<Widget> make_widget(int widget_type);

[[nodiscard]] std::unique_ptr<Widget> make_widget(WidgetType type);

auto widget = make_widget(static_cast<WidgetType>(-42));

// - What about error handling?
// - Is it possible to fail to create a Widget?
// - Is a `nullptr` return an error condition?
