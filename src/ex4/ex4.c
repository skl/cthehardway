#include <stdio.h>

int main()
{
    int age = 10;
    int height; /* uninitialised */

    printf("I am %d years old.\n"); /* missing argument */
    printf("I am %d inches tall.\n", height);

    return 0;
}
