#include <stdio.h>

int main()
{
    int age = 10;
    int height = 72;

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall.\n", height);

    /* %u is unsigned int, passing -1 appears to show 64-bit limit less one */
    printf("Integer: %d %i %u\n", 1, 2, -1);

    /* Implicit dec-oct conversion? */
    printf("Octal: %o\n", 8);

    return 0;
}
