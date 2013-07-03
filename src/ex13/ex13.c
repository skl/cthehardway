#include <stdio.h>

int main(int argc, char *argv[])
{
    if(1 == argc) {
        // Based on the fact that puts() returns a positive integer
        return puts("ERROR: You need at least one argument");
    }

    int i, x = 1; // 1 so as to ignore first argument (filename)
    char letter;

    // x++ < argc didn't seem to work here
    for(; x < argc; x++) {
        // i does not need to be initialised twice, so leave it out of the for. (now needed due to parent for loop)
        // letter can be initialised as the first statement within for. alternatively, initialse once outside of for.
        // letter value can be assigned in the second statement, the result of this assignment
        // will be a positive integer where argv[1][i] is not \0 (which has a value of 0).
        for(i = 0, letter = '\0'; (letter = argv[x][i++]);) {
            printf("i = %d\n", i);
            switch (letter) {
                case 'a':
                case 'A':
                    printf("%d: 'A'\n", i);
                    break;

                case 'e':
                case 'E':
                    printf("%d: 'E'\n", i);
                    break;

                case 'i':
                case 'I':
                    printf("%d: 'I'\n", i);
                    break;

                case 'o':
                case 'O':
                    printf("%d: 'O'\n", i);
                    break;

                case 'u':
                case 'U':
                    printf("%d: 'U'\n", i);
                    break;

                case 'y':
                case 'Y':
                    if(i > 2) {
                        printf("%d: 'Y'\n", i);
                        break; // this only breaks if conditional is true, otherwise fall-through
                    }
                    // break; // this breaks regardless of the conditional

                default:
                    printf("%d: %c is not a vowel\n", i, letter);
                    break;
            }
        }
    }

    return 0;
}
