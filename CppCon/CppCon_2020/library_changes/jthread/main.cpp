// Joining & Cancellable thread

#include <stop_token> // for std::stop_token
#include <thread>     // for std::jthread

void DoWorkPreCpp20() {
    std::thread job {[] {
        /* ... */
    }};

    try {
        // ... Do something else ...
    } catch (...) {
        job.join();
        throw; // rethrow
    }
    job.join();
}

// automatically joining:
void DoWork() {
    std::jthread job {[] {
        /* ... */
    }};
} // jthread destructor automatically cancels thread and calls join()

int main() {
    // cooperative cancellation:
    // your thread can check the token for a stop that has been requested or use a condition variable
    // any to get working up when the stop token is triggered.
    std::jthread job {[](std::stop_token token) {
        while (! token.stop_requested()) {
            // ...
        }
    }};

    // ...

    job.request_stop();

    // auto source { job.get_stop_source() };
    // source.request_stop();

    // auto token { job.get_stop_token() };
    // bool b { token.stop_requested() };
    return 0;
}
