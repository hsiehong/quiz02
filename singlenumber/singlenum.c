#include <stdio.h>

int main(void)
{
    int arr[] = {2,5,9,7,7,6,9,2,5,9,5,2,7,2,9,5,5,7,7,9,2};
    int x1, x2, x3;
    x1 = x2 = x3 = 0;
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++) {
        x3 ^= (x2 & x1 & arr[i]);
        x2 ^= (x1 & arr[i]);
        x1 ^= arr[i];
            /* in this situation k = 5, which is 101 */
        int mask = ~(x1 & ~x2 & x3);
        x3 &= mask;
        x2 &= mask;
        x1 &= mask;
    }
    printf("The single number is %d\n", x1);
    return 0;
}
