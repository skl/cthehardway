#include <stdio.h>

int main()
{
    int age = 10;
    int height = 72;

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall.\n", height);

    /* %u is unsigned int, passing -1 appears to show 64-bit limit less one */
    printf("Integer: %5d %i %u\n", 1, 2, -1);

    /* Implicit dec-oct conversion? */
    printf("Octal: %o\n", 8);

    /* Lowercase, uppercase, dec>hex conversion */
    printf("Hex: %x %X %x %a %A\n", 0xff, 0xff, 255, -0xc.90fep-2, -0XC.90FEP-2);

    printf("Float: %f %.2F\n", 1.234, -0.123);

    /* g is shortest representation of e|f (also G for E|F) */
    printf("Scientific: %e %E %g %G\n", 1e2, 3e4, 1.00000000, 1232.2353e2);

    /* single quotes for int/char, double for string */
    printf("Char: %c %s\n", 'c', "abcd");

    printf("Pointer address of 'age' var: %p\n", &age);

    /* not sure about %n */

    printf("Percent symbol: %%\n");

    printf("EOF=%d\n", EOF);

    return 0;
}
