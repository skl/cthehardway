#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef int *(*sort_cb)(int *numbers, int count, compare_cb cmp);

int *insertion_sort(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int tmp;
    int holePos;
    int *target = malloc(count * sizeof(int));

    if (!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    printf("Insertion sorting...\t");

    for (; i < count; ++i) {
        tmp = target[i];
        holePos = i;

        // original algorithm:
        //while (holePos > 0 && tmp < target[holePos-1]) {

        // modified to use comparison callback:
        while (holePos > 0 && cmp(target[holePos-1], tmp) > 0) {
            target[holePos] = target[holePos-1];
            --holePos;
        }

        target[holePos] = tmp;
    }

    return target;
}

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int tmp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    printf("Bubble sorting...\t");

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j+1]) > 0) {
                tmp = target[j+1];
                target[j+1] = target[j];
                target[j] = tmp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    }

    return a % b;
}

void test_sorting(int *numbers, int count, compare_cb cmp, sort_cb srt)
{
    int i = 0;
    int *sorted = srt(numbers, count, cmp);

    if (!sorted) die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    int j = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    printf("set {");
    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
        if (i == count - 1) {
            printf("%d", numbers[i]);
        } else {
            printf("%d,", numbers[i]);
        }
    }
    printf("}\n");

    compare_cb comparators[] = {sorted_order, reverse_order, strange_order, NULL};
    sort_cb sorters[] = {bubble_sort, insertion_sort, NULL};

    i = 0;
    while (comparators[i]) {
        j = 0;
        while (sorters[j]) {
            test_sorting(numbers, count, comparators[i], sorters[j]);
            ++j;
        }
        ++i;
    }

    free(numbers);

    return 0;
}
