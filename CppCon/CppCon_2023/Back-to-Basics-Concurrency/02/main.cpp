// Data Race

// Is this a data race ?

// auto assets = list_all_assets();
// auto liabilities = list_all_liabilities();
//
// // 1.Goal: financial report for a company
// currency_t net_worth;
// currency_t durable_goods;
// currency_t long_term_debts;
//
// std::thread goods_thread {[&durable_goods, &assets]() {
//     durable_goods = calculate_durable_goods(assets);
// }};
// std::thread debts_thread {[&long_term_debts, &liabilities]() {
//     long_term_debts = calculate_loog_term_debts(liabilities);
// }};
// net_worth = calculate_net_worth(assets, liabilities);
//
// goods_thread.join();
// debts_thread.join();
//
// // 1. Goal: financial report for a company
// create_report(net_worth, durable_goods, long_term_debts);

// auto assets = list_all_assets();
// auto liabilities = list_all_liabilities();
//
// currency_t net_worth;
// currency_t durable_goods;
// currency_t long_term_debts;
//
// // 2. Calculations can be slow
// std::thread goods_thread {[&durable_goods, &assets]() {
//     durable_goods = calculate_durable_goods(assets);
// }};
// std::thread debts_thread {[&long_term_debts, &liabilities]() {
//     long_term_debts = calculate_loog_term_debts(liabilities);
// }};
// net_worth = calculate_net_worth(assets, liabilities);
//
// goods_thread.join();
// debts_thread.join();
//
// create_report(net_worth, durable_goods, long_term_debts);

// auto assets = list_all_assets();
// auto liabilities = list_all_liabilities();
//
// currency_t net_worth;
// currency_t durable_goods;
// currency_t long_term_debts;
//
// // 3. Background thread for durable goods
// std::thread goods_thread {[&durable_goods, &assets]() {
//     durable_goods = calculate_durable_goods(assets);
// }};
//
// std::thread debts_thread {[&long_term_debts, &liabilities]() {
//     long_term_debts = calculate_loog_term_debts(liabilities);
// }};
//
// // 3. Net worth on main thread
// net_worth = calculate_net_worth(assets, liabilities);
//
// goods_thread.join();
// debts_thread.join();
//
// create_report(net_worth, durable_goods, long_term_debts);

// auto assets = list_all_assets();
// auto liabilities = list_all_liabilities();
//
// currency_t net_worth;
// currency_t durable_goods;
// currency_t long_term_debts;
//
// std::thread goods_thread {[&durable_goods, &assets]() {
//     durable_goods = calculate_durable_goods(assets);
// }};
// std::thread debts_thread {[&long_term_debts, &liabilities]() {
//     long_term_debts = calculate_loog_term_debts(liabilities);
// }};
// net_worth = calculate_net_worth(assets, liabilities);
//
// // 4. Wait for threads to complete
// goods_thread.join();
// debts_thread.join();
//
// create_report(net_worth, durable_goods, long_term_debts);

// // 5. Parent thread write (assets)
// auto assets = list_all_assets();
// // 5. Parent thread write (liabilities)
// auto liabilities = list_all_liabilities();
//
// currency_t net_worth;
// currency_t durable_goods;
// currency_t long_term_debts;
//
// // 5. Child thread read (assets)
// std::thread goods_thread {[&durable_goods, &assets]() {
//     // 5. Child thread write (durable_goods)
//     durable_goods = calculate_durable_goods(assets);
// }};
// // 5. Child thread read (liabilities)
// std::thread debts_thread {[&long_term_debts, &liabilities]() {
//     long_term_debts = calculate_loog_term_debts(liabilities);
// }};
//
//  // 5. Parent thread read (durable_goods)
// net_worth = calculate_net_worth(assets, liabilities);
//
// goods_thread.join();
// debts_thread.join();
//
// create_report(net_worth, durable_goods, long_term_debts);
