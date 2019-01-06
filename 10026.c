/*
 * 10026
 * Shoemaker's Problem
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=967
 * Johnny Lee
 */

#include <stdlib.h>
#include <stdio.h>

struct job {
    unsigned int id;
    unsigned int days;
    unsigned int fine;
    unsigned int cost;
};

int compare_job(const void *a, const void *b) {
    const struct job *ja = (const struct job*) a;
    const struct job *jb = (const struct job*) b;
    unsigned int costdiff = ja->cost - jb->cost;
    return costdiff ? costdiff : ja->id - jb->id;
}

void evaluate_costs(struct job *jobs, int count) {
    struct job *p, *q;
    struct job *last = jobs + count;
    for (p = jobs; p < last; p++) {
        p->cost = 0;
        for (q = jobs; q < last; q++) {
            if (p != q) {
                p->cost += q->fine * p->days;
            }
        }
    }
}

int main() {
    int t;
    scanf("%i", &t);

    while (t--) {
        int n;
        struct job jobs[1000];
        scanf("%i", &n);

        {
            unsigned int i;
            for (i = 0; i < n; i++) {
                unsigned int days, fine;
                struct job *pjob = jobs + i;
                scanf("%u %u", &days, &fine);
                pjob->id = i + 1;
                pjob->days = days;
                pjob->fine = fine;
            }
        }

        evaluate_costs(jobs, n);
        {
            int i;
            for (i = 0; i < n; i++) {
                printf("cost[%d] = %u\n", i, jobs[i].cost);
            }
        }

        qsort(jobs, n, sizeof(struct job), compare_job);

        printf("%i", jobs->id);

        {
            int i;
            for (i = 1; i < n; i++) {
                printf(" %i", (jobs+i)->id);
            }
        }

        printf("\n");
    }
    

    return 0;
}
