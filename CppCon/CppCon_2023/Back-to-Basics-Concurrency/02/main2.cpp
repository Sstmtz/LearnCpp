// Lock Guard -- Rall wrapper around mutexes
// - Constructor calls lock()
// - Destructor calls unlock()
// Guarantee that the mutex is always released

// std::scoped_lock
// - Constructor task one or more mutexes, calls lock() on each of the mutexes
// - Destructor calls unlock() on each of the mutexes
// - Not copyable or movable
// - Not member functions or other operations
// - Since C++17, Uses CTAD to deduce class template arguments:
//      std::scoped_lock lock(mutex_a, mutex_b);

// std::lock_guard
// - Constructor task one mutex, calls lock() on the mutexes
// - Destructor calls unlock() on the mutex
// - Not copyable or movable
// - Not member functions or other operations
// - Can't assume CTAD is avaiable:
//      std::lock_guard<std::mutex> lock(mutex_a);

// std::unique_lock
// - Owns a tmux
// - Destructor calls unlock() on the mutex if the mutex is locked
// - Has lock(), unlock() and serveral other member functions
// - Movable, but not copyable
// - Useful when you need more control over when the mutex is locked

// mutex and lock guard example

// 1. Needs synchronization
// if (transaction.amount < account.balance) { // Data race (account.balance)
//     account.balance -= transaction.amount; // Data race (account.balance)
//     record(account, transaction);
//     accept_transaction(transaction);
// } else {
//     account.balance -= overdraft_charge; // Data race (account.balance)
//     record(account, overdraft_of(transaction));
//     notify_user(account, overdraft_message);
//     reject_transaction(transaction);
// }

// 2. Incomplete synchronization
// if (transaction.amount < account.balance) { // Data race (account.balance)
//     std::scoped_lock lock(account.mutex);
//     account.balance -= transaction.amount; // Data race (account.balance)
//     record(account, transaction);
//     accept_transaction(transaction); // Don't need locked mutex
// } else {
//     std::scoped_lock lock(account.mutex);
//     account.balance -= overdraft_charge;
//     record(account, overdraft_of(transaction));
//     notify_user(account, overdraft_message);
//     reject_transaction(transaction); // Don't need locked mutex
// }

// 3. Complete synchronization
// bool transaction_ok;
// {
//     std::scoped_lock lock(account.mutex);
//     transaction_ok = transaction.amount < account.balance;
//     if (transaction_ok) {
//         account.balance -= transaction.amount;
//         record(account, transaction);
//     } else {
//         account.balance -= overdraft_charge;
//         record(account, overdraft_of(transaction));
//         notify_user(account, overdraft_message);
//     }
//     if (transaction_ok) {
//         accept_transaction(transaction);
//     } else {
//         reject_transaction(transaction);
//     }
// }
