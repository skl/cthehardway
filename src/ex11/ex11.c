#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = argc;
    while (i) {
        printf("arg %d: %s\n", i, argv[--i]);
    }

    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = num_states;
    while(i) {
        printf("state %d: %s\n", i, states[--i]);
    }

    return 0;
}
