/*
 * P100_3NP1.c
 *
 *  Created on: Jan 31, 2012
 *      Author: kayin-std
 */

#include <stdio.h>
#include <time.h>

#define false 0
#define true 1

int main() {

	int n;
	scanf("%i", &n);

	int i; for (i = 0; i < n; i++) {

		int l;
		int u;
		scanf("%i %i", &l, &u);

		int mostDivisors; // number of max divisors so far
		int whoseDivisors;

		int lowerPlusPlus = false;
		if (l == 1) {
			l++;
			mostDivisors = 1;
			whoseDivisors = 1;
			lowerPlusPlus = true;
		}

		// will not execute if l == u == 1
		long time0 = time(0);
		int j; for (j = l; j <= u; j++) {
			int divisors = 2;
			int upperlimit = j;
			// will not execute if j = 2
			int k; for (k = 2; k < upperlimit; k++) {
				if (j % k == 0) {
					divisors = divisors + 2;
					upperlimit = j / k;
				}
			} // end for k
			  // update number with most divisors
			if (mostDivisors < divisors) {
				mostDivisors = divisors;
				whoseDivisors = j;
			}
		} // end for j

		printf("Between %i and %i, %i has a maximum of %i divisors.\n",
				(lowerPlusPlus ? --l : l), u, whoseDivisors, mostDivisors);

	} // end for i

	return 0;

} // end main
