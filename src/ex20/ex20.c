#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
    debug("I have Brown Hair.");
    debug("I am %d years old.", 37);
}

int main(int argc, char *argv[])
{
    check(argc == 2, "Need an argument.");

    test_debug();

    return 0;

error:
    return 1;
}
