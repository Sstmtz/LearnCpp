#include <algorithm>
#include <cstdint>
#include <iterator>
#include <memory>
#include <vector>

class DeviceInterface;
using device_list_t = std::vector<std::unique_ptr<DeviceInterface>>;

class DeviceInterface {
public:
    virtual auto update() -> void = 0;
};

class Switch final : DeviceInterface {
public:
    [[nodiscard]] static auto find_in_env() -> device_list_t {
        // some device finding logic
    }

    auto update() -> void override {
        /* Update is_on */
    }

private:
    bool is_on {false};
};

class Dimmer final : DeviceInterface {
public:
    [[nodiscard]] static auto find_in_env() -> device_list_t {
        // some device finding logic
    }

    auto update() -> void override {
        /* Update brightness */
    }

private:
    uint_fast8_t brightness {0};
};

class DeviceManager {
public:
    DeviceManager(device_list_t devices_) : devices {std::move(devices_)} {}

    auto update() -> void {
        for (auto &device : devices) {
            device->update();
        }
    }

    [[nodiscard]] static auto get_devices() -> device_list_t {
        device_list_t output {};

        { // Switch
            auto device_list = Switch::find_in_env();
            output.insert(
                std::end(output), std::make_move_iterator(std::begin(device_list)), std::make_move_iterator(std::end(device_list)));
        }
        { // Dimmer
            auto device_list = Dimmer::find_in_env();
            output.insert(
                std::end(output), std::make_move_iterator(std::begin(device_list)), std::make_move_iterator(std::end(device_list)));
        }

        return output;
    }

    // ...

private:
    device_list_t devices {};
};

int main() {
    DeviceManager manager {DeviceManager::get_devices()};
    manager.update();
}
