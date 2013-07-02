#include <stdio.h>

int main(int argc, char *argv[])
{
    /* puts() ends with a line feed, printf() does not */
    puts("Hello world.");

    /* EOF is an integer constant */
    printf("%d", EOF);

    /* puts() returns a positive integer on success */
    printf("%d", puts("ab"));

    return 0;
}
