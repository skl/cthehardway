#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "dbg.h"

double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec * 1e-6;
}

int normal_copy(char *from, char *to, int count)
{
    int i =0;

    for (i = 0; i < count; i++) {
        to[i] = from[i];
    }

    return i;
}

int duffs_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8) {
        case 0: do {
            *to++ = *from++;
        case 7: *to++ = *from++;
        case 6: *to++ = *from++;
        case 5: *to++ = *from++;
        case 4: *to++ = *from++;
        case 3: *to++ = *from++;
        case 2: *to++ = *from++;
        case 1: *to++ = *from++;
            } while (--n > 0);
        }
    }

    return count;
}

int zeds_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8) {
        case 0:
        again: *to++ = *from++;
        case 7: *to++ = *from++;
        case 6: *to++ = *from++;
        case 5: *to++ = *from++;
        case 4: *to++ = *from++;
        case 3: *to++ = *from++;
        case 2: *to++ = *from++;
        case 1: *to++ = *from++;
            if (--n > 0) {
                goto again;
            }
        }
    }

    return count;
}

int valid_copy(char *data, int count, char expects)
{
    int i = 0;

    for (i = 0; i < count; i++) {
        if (data[i] != expects) {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    char from[1000] = {'a'};
    char to[1000] = {'c'};
    int rc = 0;
    double start;

    memset(from, 'x', 1000);
    memset(to, 'y', 1000);
    check(valid_copy(to, 1000, 'y'), "Not initialised right.");

    start = get_time();
    rc = normal_copy(from, to, 1000);
    log_info("normal_copy():%f", get_time() - start);

    check(rc == 1000, "Normal copy failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Normal copy failed.");

    memset(to, 'y', 1000);

    start = get_time();
    memcpy(to, from, 1000);
    log_info("memcpy():%f", get_time() - start);

    check(valid_copy(to, 1000, 'x'), "memcpy failed.");

    memset(to, 'y', 1000);

    start = get_time();
    rc = duffs_device(from, to, 1000);
    log_info("duffs_device():%f", get_time() - start);

    check(rc == 1000, "Duff's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Duff's device failed.");

    memset(to, 'y', 1000);

    start = get_time();
    rc = zeds_device(from, to, 1000);
    log_info("zeds_device():%f", get_time() - start);

    check(rc == 1000, "Zed's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Zed's device failed.");

    return 0;

error:
    return 1;
}
