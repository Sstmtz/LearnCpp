#include <map>
#include <utility>

// before C++17:
std::map<int, person> m = /* ... */;

person p = /* ... */;
auto   res = m.emplace(42, std::move(p));
// if the insertion failed, was p moved ?

person p = /* ... */;
m[42] = std::move(p);
// value type must be befault constructible
// did we insert or assign ?
// what iterator is the key at ?

// since C++17:
std::map<int, person> m = /* ... */;

person p = /* ... */;
auto   res = m.try_emplace(42, std::move(p));
// if the insertion failed, p wasn't moved.

person p = /* ... */;
auto   res = m.insert_or_assign(std::move(p));
// return info as a pair<iterator, bool>.
