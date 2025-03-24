// Semaphore
// Lightweight synchronization primitives
// Can be used to implement any other synchronization concept:
// mutex, latches, barries, ...

// Latches & barriers
// Help with thread coordination

// Waitting & notifing on std::atomic
// Wait/Block for an atomic object to change its value, notified by notification function
// Methods: wait() notify_one() notify_all()

#include <barrier>
#include <latch>
#include <semaphore>
