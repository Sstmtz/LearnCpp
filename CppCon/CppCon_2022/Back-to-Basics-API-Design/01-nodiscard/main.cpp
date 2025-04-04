// Use Better Naming

template <typename T>
class vector {
public:
    bool empty() const;
};

// Easy or Hard to use wrong? Why?
// - What does empty() do?
// - Whay Happens if we drop the return value?
// - What kind of error handling does it have?

template <typename T>
class vector {
public:
    [[nodiscard]] bool is_empty() const noexcept;
};
