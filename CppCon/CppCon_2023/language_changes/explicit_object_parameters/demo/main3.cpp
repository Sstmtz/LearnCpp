#include <string>

class Person {
public:
    Person(std::string name) : m_name {std::move(name)} {}

    // before C++23:
    // class often have cosnt and non-const overloads of members,
    // possibly ref-qualified:
    std::string &GetName() & {
        return m_name;
    }

    std::string const &GetName() const & {
        return m_name;
    }

    std::string &&GetName() && {
        return std::move(m_name);
    }

    // since C++23:
    // replace all 3 overloads with:
    template <typename Self>
    auto &&GetName(this Self &&self) {
        return std::forward<Self>(self).m_name;
    }

private:
    std::string m_name;
};

int main() {
    return 0;
}
