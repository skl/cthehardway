#include <stdio.h>

void stack_overflow()
{
    double var = 9999999.9999999;

    printf(".");

    stack_overflow();
}

int main(int argc, char *argv[])
{
    stack_overflow();

    return 0;
}
