#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "jemalloc_div.h"

int main(void)
{
    freopen("result_O3", "w", stdout);         // write filename
    div_info_t DIV;
    size_t temp;
    struct timespec start, end;
    srand(time(NULL));
    printf("divisor  fast_time   norm_time\n");
    for (size_t i = 2; i <= 10000; i++) {
        div_init(&DIV, i);
        uint64_t dividend = rand() % UINT_MAX;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        temp = div_compute(&DIV, dividend);
        clock_gettime(CLOCK_MONOTONIC, &end);
        long long fast_cost = (long long)(end.tv_sec * 1e9 + end.tv_nsec) -     \
                              (long long)(start.tv_sec * 1e9 + start.tv_nsec);
        clock_gettime(CLOCK_MONOTONIC, &start);
        temp = dividend / i;
        clock_gettime(CLOCK_MONOTONIC, &end);
        long long norm_cost = (long long)(end.tv_sec * 1e9 + end.tv_nsec) -     \
                              (long long)(start.tv_sec * 1e9 + start.tv_nsec);
        printf("%-7ld  %-7lld %-7lld\n", i, fast_cost, norm_cost);
    }
    return 0;
}
