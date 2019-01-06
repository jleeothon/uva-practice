#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 562 - Dividing coins
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=503
 * Wrong answer
 */

int compare(const void* a, const void* b) {
    return *((int *)b) - *((int *)a);
}

int main() {
    int n; /* number of test cases */
    scanf("%d", &n);
    while (n--) {
        int m; /* number of coins */
        int coins[100];
        int *p, *plast;
        scanf("%d", &m);
        for (p = coins, plast = coins + m; p < plast; p++) {
            scanf("%d", p);
        }
        
        int a, b;
        qsort(coins, (size_t)m, sizeof int, compare);
        a = b = 0;
        for (p = coins, plast = coins + m; p < plast; p++) {
            if (a < b) {
                a += *p;
            } else {
                b += *p;
            }
        }

        int d = abs(a - b);
        printf("%d\n", d);
    }

    return 0;
}
