/*
 * 10976 Fractions Again?!
 * http://uva.onlinejudge.org/external/109/10976.html
 * Johnny Lee
 * Accepted
 */

/*
for every i between k+1 and 2k
    1 / k         = 1 / x + 1 / i
    1 / k - 1 / i = 1 / x
    x             = 1 / (1 / k - 1 / i)
    x             = 1 / ((i - k) / i / k)
    x             = i * k / (i - k)
*/

#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

long long int x[10000], y[10000];
long long int n;
long long int k;

void evalFractions() {
    int i, k2;
    i = k;
    k2 = 2 * k;
    while (++i <= k2) {
        long long int num = i * k;
        int den = i - k;
        if (num % den == 0) {
            x[n] = num / den;
            y[n] = i;
            n++;
        }
    }
}

void printFractions() {
    int i;
    printf("%d\n", n);
    for (i = 0; i < n; i++) {
        printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
    }
}


int main() {
    while (scanf("%d", &k) != EOF) {
        n = 0;
        evalFractions();
        printFractions();
    }
    return 0;
}
