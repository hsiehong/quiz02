#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include "quickmod.h"

/*
measure the time of fast mod and normal mod
make each method mod 100 thousand times then record it.
*/

int main(void)
{
    freopen("result_O3", "w", stdout);
    struct timespec begin, end;
    long long int fast_mod, nor_mod, r;
    uint32_t dividend;
    srand(time(NULL));
    printf("#num\tfastmod\tnormmod\n");
    for(uint32_t m = 0; m < 100000; m++) {
        dividend = rand() % 1000000;
            /* get time for fast mod */
        clock_gettime(CLOCK_MONOTONIC, &begin);
        r = quickmod(dividend);
        clock_gettime(CLOCK_MONOTONIC, &end);
        fast_mod = (long long)(end.tv_sec * 1e9 + end.tv_nsec) -      \
                   (long long)(begin.tv_sec * 1e9 + begin.tv_nsec);
            /* get time for norm mod */
        clock_gettime(CLOCK_MONOTONIC, &begin);
        r = dividend % 3;
        clock_gettime(CLOCK_MONOTONIC, &end);
        nor_mod = (long long)(end.tv_sec * 1e9 + end.tv_nsec) -      \
                  (long long)(begin.tv_sec * 1e9 + begin.tv_nsec);
            /* result */
        assert(quickmod(dividend) == dividend % 3);
        printf("%-7d\t%-8lld\t%-8lld\n", m, fast_mod, nor_mod);
        // printf("Time elapse for fast mod: %8lld ns\n", fast_mod);
        // printf("Time elapse for norm mod: %8lld ns\n", nor_mod);
    }
    return 0;
}
