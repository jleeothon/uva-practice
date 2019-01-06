/*
10943
How do you add?
http://uva.onlinejudge.org/external/109/10943.html
Johnny Lee
Status: wrong answer :(
*/

/*
State: pending
*/

/*

for k = 1, answer = 1

for k = 2, answer = N + 1
    0 -> 1
        0+0
    1 -> 2
        0+1, 1+0
    2 -> 3
        0+2, 1+1, 2+0
    3 -> 4
        0+3, 1+2, 2+1, 3+0

for k = 3, answer = 
    1 -> 3
        0+0+1, 0+1+0, 1+0+0
    2 -> 6
        0+0+2, 0+1+1, 0+2+0, 1+0+1, 1+1+0, 2+0+0
    3 -> 10
    4 -> 15

howDoYouAdd(n > 0, k) = 1
howDoYouAdd(1, k) = n
howDoYouAdd(n, 0) = 0
howDoYouAdd(n, 1) = 1
howDoYouAdd(n, 2) = n + 1
howDoYouAdd(n, k) = howDoYouAdd(n - 1, k) + howDoYouAdd(n, k - 1)

*/

#include <stdio.h>

#define TSIZE 101

unsigned long long int t[TSIZE][TSIZE] = {0};

/* DP stack */
struct nk {
    unsigned int n;
    unsigned int k;
};

struct nk p[100];
struct nk *pnext = p; /* top of the pending stack (this location empty) */

int nk_available() {
    return pnext - p;
}
void nk_push(unsigned int n, unsigned int k) {
    struct nk next;
    next.n = n;
    next.k = k;
    *pnext++ = next;
}
void nk_pop(unsigned int *n, unsigned int *k) {
    struct nk t = *pnext--;
    *n = t.n;
    *k = t.k;
}
void nk_remove() {
    pnext--;
}
void nk_top(unsigned int *n, unsigned int *k) {
    struct nk t = pnext[-1];
    *n = t.n;
    *k = t.k;
}
/* end DP stack */

void prepare() {
    int i;
    i = TSIZE;
    while (i--) {
        t[0][i] = 1;
        t[1][i] = i; /* optional */
        t[i][0] = 0;
        t[i][1] = 1;
        t[i][2] = i + 1; /* optional */
    }
}

void evalPending() {
    unsigned int n, k;
    while (nk_available()) {
        nk_top(&n, &k);
        if (t[n][k] != 0) {
            nk_remove();
            continue;
        }
        int pending = 0;
        if (t[n-1][k] == 0) {
            nk_push(n - 1, k);
            pending = 1;
        }
        if (t[n][k-1] == 0) {
            nk_push(n, k - 1);
            pending = 1;
        }
        if (!pending) {
            t[n][k] = t[n-1][k] + t[n][k-1];
            nk_remove();
        }
    }
}

unsigned long long int howDoYouAdd(unsigned int n, unsigned int k) {
    nk_push(n, k);
    evalPending();
    unsigned long long int r = t[n][k];
    return r;
}

int main() {
    unsigned int n, k;
    prepare();
    while (scanf("%u %u", &n, &k) != EOF && (n || k)) {
        unsigned long long int r = howDoYouAdd(n, k);
        r %= 1000000;
        printf("%llu\n", r);
    }
    return 0;
}
