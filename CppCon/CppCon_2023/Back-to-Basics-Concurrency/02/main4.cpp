// std::atomic

#include <cstdio>
#include <mutex>
#include <thread>

using namespace std::chrono_literals;

// Loop example -- has data race

// bool flag = false;
//
// int main() {
//     std::thread t([]() {
//         std::printf("Waiting... \n");
//         while (not flag) {} // compiler assumes infinite loop
//         std::printf("Flag changed\n");
//     });
//     std::this_thread::sleep_for(500ms);
//     std::printf("Setting flag\n");
//     flag = true;
//     t.join();
//     std::printf("Done\n");
// }

// Loop example -- deadlock

// bool flag = false;
// std::mutex flag_mutex;
//
// int main() {
//     std::thread t([]() {
//         std::printf("Waiting...\n");
//         {
//             std::scoped_lock lock(flag_mutex);
//             while (not flag) {}
//         }
//         std::printf("Flag changed\n");
//     });
//     std::this_thread::sleep_for(500ms);
//     std::printf("Setting flag\n");
//     {
//         std::scoped_lock lock(flag_mutex);
//         flag = true;
//     }
//     t.join();
//     std::printf("Done\n");
// }

// Loop example -- mutex

// bool flag = false;
// std::mutex flag_mutex;
//
// int main() {
//     std::thread t([]() {
//         std::printf("Waiting...\n");
//         bool local_flag;
//         do {
//             std::scoped_lock lock {flag_mutex};
//             local_flag = flag;
//         } while (not local_flag);
//         std::printf("Flag changed\n");
//     });
//     std::this_thread::sleep_for(500ms);
//     std::printf("Setting flag\n");
//     {
//         std::scoped_lock lock(flag_mutex);
//         flag = true;
//     }
//     t.join();
//     std::printf("Done\n");
// }

// Loop example -- atomic

std::atomic<bool> flag {false};

int main() {
    std::thread t([]() {
        std::printf("Waiting... \n");
        while (not flag) {} // compiler assumes infinite loop
        std::printf("Flag changed\n");
    });
    std::this_thread::sleep_for(500ms);
    std::printf("Setting flag\n");
    flag = true;
    t.join();
    std::printf("Done\n");
}
