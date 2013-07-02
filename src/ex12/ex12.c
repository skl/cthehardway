#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 1) {
        puts("You only have one argument.");
    } else if (argc > 1 && argc < 4) {
        puts("Here's your arguments:");

        for (i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        puts("You have too many arguments.");
    }

    return 0;
}
