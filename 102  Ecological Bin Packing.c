/*
 *
 */

#include <stdio.h>


int main() {

    int b1, g1, c1,
        b2, g2, c2,
        b3, g3, c3;
    int cases[6];
    while (scanf("%d %d %d %d %d %d %d %d %d",
                 &b1, &g1, &c1,
                 &b2, &g2, &c2,
                 &b3, &g3, &c3
                 ) != EOF) {
        cases[0] = b2 + b3 + c1 + c3 + g1 + g2;
        cases[1] = b2 + b3 + g1 + g3 + c1 + c2;
        cases[2] = c2 + c3 + b1 + b3 + g1 + g2;
        cases[3] = c2 + c3 + g1 + g3 + b1 + b2;
        cases[4] = g2 + g3 + b1 + b3 + c1 + c2;
        cases[5] = g2 + g3 + c1 + c3 + b1 + b2;
        
        int ans = 0;
        int i;
        for (i = 1; i < 6; i++) {
            if (cases[i] < cases[ans]) {
                ans = i;
            }
        }

        switch (ans) {
            case 0:
                printf("BCG %d\n", cases[0]);
                break;
            case 1:
                printf("BGC %d\n", cases[1]);
                break;
            case 2:
                printf("CBG %d\n", cases[2]);
                break;
            case 3:
                printf("CGB %d\n", cases[3]);
                break;
            case 4:
                printf("GBC %d\n", cases[4]);
                break;
            case 5:
                printf("GCB %d\n", cases[5]);
                break;
            default:
                puts("ERROR");
                break;
        }
    }

    return 0;
}

