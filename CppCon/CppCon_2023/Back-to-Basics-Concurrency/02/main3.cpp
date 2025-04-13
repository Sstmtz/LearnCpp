// Deadlock

// Thread 1
// {
//     std::scoped_lock la1(mutex_a);
//     chanage_data(data_a);
//     {
//         std::scoped_lock lb1(mutex_b);
//         chanage_data(data_a, data_b);
//     }
// }

// Thread 2
// {
//     std::scoped_lock lb2(mutex_b);
//     chanage_data(data_b);
//     {
//         std::scoped_lock la2(mutex_a);
//         chanage_data(data_a, data_b);
//     }
// }

// std::scoped_lock is useful for avoiding deadlock
// If given multiple mutexes, always locks them in the same order
//
// std::scoped_lock lockA {mutexA, mutexB, mutexC}; // no deadlock
// std::scoped_lock lockB {mutexC, mutexA, mutexB}; // no deadlock

// Thread 1
// {
//     std::scoped_lock l1(mutex_a, mutex_b);
//     chanage_data(data_a);
//     chanage_data(data_a, data_b);
// }

// Thread 2
// {
//     std::scoped_lock l2(mutex_b, mutex_a);
//     chanage_data(data_b);
//     chanage_data(data_a, data_b);
// }
