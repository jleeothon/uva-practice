/*
 * The Monkey and the Oiled Bamboo
 * http://uva.onlinejudge.org/external/120/12032.html
 * Johnny Lee
 * Accepted
 */

#include <stdio.h>

#define MAX_RUNG_HEIGHT 10000000

int rungs[100005] = {0};
int n;

/* returns the strength left at the end of the iteration */
int jumpjump(int k) {
    int *i = rungs, *last = rungs + n;
    while (i < last) {
        int d = i[1] - i[0];
        if (d == k) {
            k--;
        } else if (d > k) {
            return -1;
        }
        i++;
    }
    return k;
}

int bsearchjump() {
    int min = 0, max = MAX_RUNG_HEIGHT;
    int mink;
    int minStrengthLeft = 0;
    int mid = (max + min) / 2;
    do {
        int strengthLeft = jumpjump(mid);
        if (strengthLeft < 0) {
            min = mid;
        } else if (strengthLeft > 0) {
            if (strengthLeft < minStrengthLeft || !minStrengthLeft) {
                minStrengthLeft = strengthLeft;
                mink = mid;
            }
            max = mid;
        } else {
            return mid;
        }
        mid = (max + min) / 2;
    } while (min != mid);
    if (!minStrengthLeft) {
        minStrengthLeft = jumpjump(MAX_RUNG_HEIGHT);
    }
    return mink;
}

int main() {
    int t;
    int i, j;
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d", &n);
        /* the first location is always 0 */
        for (j = 1; j <= n; j++) {
            scanf("%d", rungs + j);
        }
        int mink = bsearchjump();
        printf("Case %d: %d\n", i, mink);
    }
    return 0;
}
