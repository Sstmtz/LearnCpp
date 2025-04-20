// Example: std::function

// Would you provide an abstraction for callable by means of an inheritance hierarchy?

#include <functional>

class Command {
public:
    virtual void operator()(int) const = 0;
    // ...
};

class PrintCommand : public Command { /* ... */
};

class SearchCommand : public Command { /* ... */
};

class ExecuteCommand : public Command { /* ... */
};

void f(Command *command);

// No, you wouldn't. You would use std::function instead!

void f(std::function<Command> *command);

// std::function instead of inheritance:
// - no inheritance hierarchies
// - non-intrusive
// - no pointers
// - no manual dynamic allocation
// - no manual life-time management
// - less code to write
