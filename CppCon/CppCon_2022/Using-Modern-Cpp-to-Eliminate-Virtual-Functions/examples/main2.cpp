#include <concepts>
#include <cstdint>
#include <tuple>
#include <vector>

template <typename T>
concept CDevice = requires(T device) {
    { T::find_in_env() } -> std::same_as<std::vector<T>>;
    { device.update() } -> std::same_as<void>;
};

class Switch {
public:
    [[nodiscard]] static auto find_in_env() -> std::vector<Switch> {
        // some device finding logic
    }

    auto update() -> void {
        /* Update is_on */
    }

private:
    bool is_on {false};
};

class Dimmer final {
public:
    [[nodiscard]] static auto find_in_env() -> std::vector<Dimmer> {
        // some device finding logic
    }

    auto update() -> void {
        /* Update brightness */
    }

private:
    uint_fast8_t brightness {0};
};

template <CDevice... TDevices>
class DeviceManager {
public:
    DeviceManager() : devices(get_devices()) {}

    auto update() -> void {
        std::apply(
            [this](auto &...device_lists) {
                (update_device(device_lists), ...);
            },
            devices);
    }

private:
    using device_list_t = std::tuple<std::vector<TDevices>...>;

    auto update_device(auto &device_list) -> void {
        for (auto &device : device_list) {
            device.update();
        }
    }

    [[nodiscard]] static auto get_devices() -> device_list_t {
        return std::tuple {TDevices::find_in_env()...};
    }

    device_list_t devices {};
};

int main() {
    DeviceManager<Switch, Dimmer> manager {};
    manager.update();
    return 0;
}
