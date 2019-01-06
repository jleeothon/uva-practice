#include <stdio.h>
#include <stdlib.h>

int main() {

	unsigned int N;
	scanf("%i", &N);
	int ladies[50000];
	int *l = ladies;
	int *ladiesEnd = ladies + N;
	while (l < ladiesEnd) {
		scanf("%i", l);
		l++;
	}

	unsigned int Q; /* known to be greater than 1 */
	scanf("%i", &Q);
	unsigned q = Q;
	int playboy;
	do {
		scanf("%i", &playboy);
		int *hi, *lo, *mi, miVal;
		/* mi will look for the lady inmediately shorter */
		/* BINARY SEARCH (ITERATIVE) */
		lo = ladies;
		hi = ladiesEnd;
		int shorter = -1, taller = -1;
		do {
			mi = (int*) ((*lo + *hi) >> 1); /* new mid position */
			miVal = *mi;
			if (mi != lo) {
				/* more than two elements left */
				if (miVal < playboy) {
					if (*(mi+1) < playboy) {
						/* lookup upper half */
						lo = mi;
					} else {
						/* bingo ! */
						break;
					}
				} else {
					/* lookup lower half */
					hi = mi;
				}
			} else {
				break;
			}
		} while (1);
		/* ITERATION BROKEN */
		if (miVal < playboy) {
			shorter = miVal;
		} else  if (miVal == playboy) {
			int *s = mi, *t = mi;
			while (--s >= ladies) if (*s < playboy) shorter = *s;
			while (++t < ladiesEnd)	if (*t > playboy) taller = *t;
		} else {

		}

		int *s = mi, *t = mi;



		break;
		/* END BINARY SEARCH */
	} while (--q);

	return 0;

}
