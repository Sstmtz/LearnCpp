// UNIQUE_PTR

// Collection

#include <memory>
#include <utility>
#include <vector>

// std::vector<std::unique_ptr<T>> just_works;
//
// {
//     std::vector<std::unique_ptr<T>> v;
//     v.push_back(std::make_unique<T>());
//     std::unique_ptr<T> a;
//     v.push_back(std::move(a));
//     v[0] = std::make_unique<T>();
//     auto it = v.begin();
//     v.erase(it);
// }
