/*
 * Horror Dash
 * http://uva.onlinejudge.org/external/117/11799.html
 * Johnny Lee
 * Accepted
 */

#include <stdio.h>

int t, T;
int n;
int c;

int main() {
    scanf("%d", &t);
    T = t;
    while (t--) {
        scanf("%d", &n);
        int max = 0;
        while (n--) {
            scanf("%d", &c);
            if (c > max) {
                max = c;
            }
        }
        printf("Case %d: %d\n", T - t, max);
    }
    return 0;
}

