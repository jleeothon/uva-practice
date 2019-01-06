/*
 * Event Planning
 * http://uva.onlinejudge.org/external/115/11559.html
 * Johnny Lee
 */

#include <stdio.h>

int main() {
    int people, budget, hotels, weeks;
    while (scanf("%d %d %d %d", &people, &budget, &hotels, &weeks) != EOF) {
        int min = -1;
        while (hotels--) {
            int price;
            int available;
            int weeks2 = weeks;
            int total;
            int ignore;
            scanf("%d", &price);
            total = price * people;
            /* ignore if exceeds budget current lowest price known */
            ignore = (total > budget) || ((total > min) && (min != -1));
            while (weeks2--) {
                scanf("%d", &available);
                if (!ignore && available >= people) {
                    min = total;
                }
            }
        }
        if (min == -1) {
            printf("stay home\n");
        } else {
            printf("%d\n", min);
        }
    }
    return 0;
}
