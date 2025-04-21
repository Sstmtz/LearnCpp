// 3. Value-Initialization Difficulties

// As mentioned, the parsing rules made value-initialization difficult in some contexts:

#include <cstddef>

class demo_str {
private:
    std::size_t stored_length;
    char *actual_str;
};

demo_str ds1;              // default-init
demo_str ds2();            // oops, declares a function!
demo_str ds3 = demo_str(); // value-init/copy-init

// The roundabout form of value-initialization isn't very clear.
// - It's easy to confuse it for a more roundabout form of default-initialization
// (maybe by a programmer who's used to a different language)
