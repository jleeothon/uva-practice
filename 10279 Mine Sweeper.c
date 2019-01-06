#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int t, n;

int field0[10][10];
char field1[10][10];

int stacki[100], stackj[100], stackc;

int field1c;

/* mined 1, unmined 0 */
const char mined = '*';
const char unmined = '.';
/* touched 1, untouched 0 */
const char touched = 'x';
const char untouched = '.';

int is_valid_i_j(int i, int j) {
	return (i > 0 && i < n && j > 0 && j < n) ? 1 : 0; 
}

void calc_mined_neighbours(int i, int j) {
	int mined_neigbours = 0;
	if (is_valid_i_j(i-1, j) && field0[i-1][j]) mined_neigbours += 1;
	if (is_valid_i_j(i+1, j) && field0[i+1][j]) mined_neigbours += 1;
	if (is_valid_i_j(i, j-1) && field0[i][j-1]) mined_neigbours += 1;
	if (is_valid_i_j(i, j+1) && field0[i][j+1]) mined_neigbours += 1;
	if (is_valid_i_j(i-1, j-1) && field0[i-1][j-1]) mined_neigbours += 1;
	if (is_valid_i_j(i-1, j+1) && field0[i-1][j+1]) mined_neigbours += 1;
	if (is_valid_i_j(i+1, j-1) && field0[i+1][j-1]) mined_neigbours += 1;
	if (is_valid_i_j(i+1, j+1) && field0[i+1][j+1]) mined_neigbours += 1;
	return mined_neigbours;
}

void print_field0() {
	for ()
}

int main() {
	scanf("%d", &t);
	int i, j, k;
	char *bufferc;
	while (t--) {
		for (i = 0; i < 10; i++) {
			memset(field0[i], 0, 10*sizeof(char));
		}
		scanf("%d\n", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%c", bufferc);
				field0[i][j] = *bufferc == mined ? 1 : 0;
			}
			getchar();
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%c", &(field1[i][j]));
			}
			getchar();
		}
		stacki[0] = stackj[0] = 0;
		stackc = 0;
		while (stackc > -1) {
			i = stacki[stackc];
			j = stackj[stackc];
			if (!is_valid_i_j(i, j) ||
					(isdigit(field1[i][j])))
				continue;
			field1[i][j] = calc_mined_neighbours(i, j);
			stacki[stackc]
		}

	}
	return 0;
}