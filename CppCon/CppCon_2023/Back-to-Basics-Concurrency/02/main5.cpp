// std::atmoic

#include <atomic>
#include <cstdio>
#include <mutex>
#include <thread>
#include <vector>

// Increment example -- has data race

// int counter = 0;
//
// int main() {
//     std::vector<std::thread> threads;
//     threads.reserve(100);
//     auto increment = []() {
//         for (int i = 0; i < 50; ++i) {
//             ++counter;
//         }
//     };
//     for (int i = 0; i < 100; ++i) {
//         threads.push_back(std::thread(increment));
//     }
//     for (std::thread &t : threads) {
//         t.join();
//     }
//     std::printf("%d\n", counter); // random values that fluctuate around 5000
// }

// Increment example -- mutex
// Use mutex to resolve data race

// int counter = 0;
// std::mutex counter_mutex;
//
// int main() {
//     std::vector<std::thread> threads;
//     threads.reserve(100);
//     auto increment = []() {
//         for (int i = 0; i < 50; ++i) {
//             std::scoped_lock lock {counter_mutex};
//             ++counter;
//         }
//     };
//     for (int i = 0; i < 100; ++i) {
//         threads.push_back(std::thread(increment));
//     }
//     for (std::thread &t : threads) {
//         t.join();
//     }
//     std::printf("%d\n", counter); // 5050
// }

// Increment example -- atomic
// Compared to use `mutex`, `atomic` has slightly lower performance overhead.
// But it is still not ideal, there are too many updates to the shared status.

// std::atomic<int> counter {0};
//
// int main() {
//     std::vector<std::thread> threads;
//     threads.reserve(100);
//     auto increment = []() {
//         for (int i = 0; i < 50; ++i) {
//             ++counter;
//         }
//     };
//     for (int i = 0; i < 100; ++i) {
//         threads.push_back(std::thread(increment));
//     }
//     for (std::thread &t : threads) {
//         t.join();
//     }
//     std::printf("%d\n", counter.load()); // 5000
// }

// Increment example -- fewer updates
// A better solution is to avoid frequently updating the counter,
// allowing each thread to count locally and only updating the shared status at the end.

std::atomic<int> counter {0};

int main() {
    std::vector<std::thread> threads;
    threads.reserve(100);
    auto increment = []() {
        int local_counter = 0;
        for (int i = 0; i < 50; ++i) {
            ++local_counter;
        }
        counter += local_counter;
    };
    for (int i = 0; i < 100; ++i) {
        threads.push_back(std::thread(increment));
    }
    for (std::thread &t : threads) {
        t.join();
    }
    std::printf("%d\n", counter.load()); // 5000
}
