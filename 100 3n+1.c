#include <stdio.h>
#include <stdlib.h>


int cyclelength(int* cyclelens, int n) {
	int count = 0;
	while (n != 1) {
		if (cyclelens[n] != -1) {
			count += cyclelens[n];
			break;
		}
		if (n & 1) n = 3 * n + 1;
		else n = n / 2;
		count ++;
	}
	printf("n = %d, count = %d\n", n, count);
	getchar();
	return count;
}


int main() {

	int i, j, ii, jj;
	int max;
	int* cyclelens;

	cyclelens = (int*) malloc(1000001 * sizeof(int));

	int k = 1000001;
	while (--k) cyclelens[k] = -1;
	
	k = 1000001;
	while (--k) {
		cyclelens[k] = cyclelength(cyclelens, k);
	}

	k = 1000001;
	while (--k) {
		printf("k = %d, length = %d\n", k, cyclelens[k]);
	}

	while (scanf("%d %d", &i, &j) != EOF) {
		if (i < j) ii = i, jj = j;
		else ii = j, jj = i;
		max = cyclelens[ii];
		for (k = ii+1; k <= jj; k++) {
			if (cyclelens[k] > max) max = cyclelens[k];
		}
		printf("%d %d %d\n", i, j, max);
	}
	return 0;
}