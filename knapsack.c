#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

/*
where:
	m := matrix of c rows and cap columns
	c := item count
	cap := capacity of the knapsack
	w := weights
	b := benefits
*/


int knapsack ( int **m, int c, int cap, int* w, int* b ) {
	int i, j;
	for (j = 0; j < cap; j++) m[0][j] = 0;
	for (i = 0; i < c; i++) m[i][0] = 0;
	for (i = 1; i < c; i++) {
		for (j = 1; j < cap; j++) {
			if (j < w[i]) m[i][j] = m[i-1][j];
			else m[i][j] = max(m[i-1][j], m[i-1][j-w[i]]+b[i]);
		} // end for columns
	} // end for rows
	return m[i-1][j-1];
	return 0;
} // end knapsack

int main() {
	int  ** m;
	m = calloc(5, sizeof(int));
	int i;
	for( i=0; i<5; i++ ) m[i] = calloc( 16, sizeof(int) );
	int c = 5, cap = 16;
	int w[] = {1, 3, 6, 20, 50};
	int b[] = {2, 5, 10, 100, 110};
	printf("%d\n", knapsack(m, c, cap, w, b));
	return 0;
}