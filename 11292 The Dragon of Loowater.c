#include <stdlib.h>
#include <stdio.h>

int n, m;
int dheads[20000], knights[20000];
int i, j;
int *dhead_i, *knight_i;
int cost;
int salvable;

int comp(const void* ref, const void* other) {
	return *((int*)ref) - *((int*)other);
}


void printArray(const char* message, int* arr, int num) {
	printf("%s ", message);
	int i; for (i = 0; i < num; i++) {
		printf("%i ", arr[i]);
	}
	printf("\n");
}

int main() {
	while (1) {
		/* readings */
		scanf("%i %i", &n, &m);
		if (n == 0) break;
		i = n; dhead_i = dheads;
		while (i--) {
			scanf("%i", dhead_i);
			dhead_i++;
		}
		i = m; knight_i = knights;
		while (i--) {
			scanf("%i", knight_i);
			knight_i++;
		} *knight_i = -1;
		/* Sort */
		qsort(dheads, n, sizeof(int), comp);
		qsort(knights, m, sizeof(int), comp);
		/* printArray("dheads", dheads, n); */
		/* printArray("knights", knights, m); */
		/* Now for the cool part, bitches! */
		cost = 0;
		salvable = 1;
		i = n; dhead_i = dheads;
		j = m; knight_i = knights;
		while (salvable && i--) {
			while (1) {
				if (*knight_i >= *dhead_i) {
					cost += *(knight_i++);
					break;
				} else if (--j) {
					knight_i++;
				} else {
					salvable = 0;
					break;
				}
			}
			dhead_i++;
		} /* end while salvable and not all dragonheads checked */
		if (salvable) {
			printf("%i\n", cost);
		} else {
			printf("Loowater is doomed!\n");
		}
	} /* end while 1 (test cases) */
	
	return 0;
	
	
}

/*
 * Have knights' and dragonheads' measures ordered.
 * for each dragonhead
 *   while true
 *     if current knight can behead current dragonhead
 *       sum the knight's height to cost
 *       break while true
 *     if current knight cannot
 *       if there's next knight
 *         bring him!
 *       else 
 *         doom
 * end for dragonheads
 * print cost
 */
