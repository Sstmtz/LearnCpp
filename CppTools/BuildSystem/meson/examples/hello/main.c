#include "hello.h"
#include "version.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define shift(xs, xs_sz) (assert(xs_sz > 0), --xs_sz, *xs++)

int main(int argc, char **argv) {

    char const *program_name = shift(argv, argc);

    if (argc > 0) {
        char const *command_name = shift(argv, argc);

        if (strcmp(command_name, "version") == 0) {
            printf("%s Version: %s\n", program_name, GIT_COMMIT_HASH);
            return 0;
        } else {
            fprintf(stderr, "Usage: %s [version]\n", program_name);
            fprintf(stderr, "ERROR: unknown command %s\n", command_name);
        }
    }

    hello();
}
