#include <stdio.h>

/*
 * Prints the rotation of an N x N matrix by 90 degrees clockwise.
 * Each groups of lines include:
 * * line 1: N
 * * next N lines: the description of each row.
 */

// matrix[row][col]

int m[1000][1000];
int r[1000][1000];

int N;
int n;

int i. j;

int main() {
	while (scanf("%i", &N) != EOF) {
		n = N-1;
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
			scanf("%i", m[i][j]);
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
			r[j][n-i] = m[i][j];
		// if would be faster to print without rotation
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%3i", r[i][j]);
			}
			printf("\n");
		} 
	}
}