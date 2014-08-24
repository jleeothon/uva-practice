#include <stdlib.h>
#include <stdio.h>

void print_matrix(int **matrix, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%4hu", matrix[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char ** argv) {
	int x, y;
	x = (int)(atoi(argv[1]));
	y = (int)(atoi(argv[2]));
	int **m = (int **)malloc(x * sizeof(int*));
	for (int n = 0; n < x; n++) m[n] = (int*) malloc(y*sizeof(int));	

	int count = 1;
	int i = 0, j = -1;
	int north, south, east, west;
	north = west = 0;
	south = x - 1;
	east = y - 1;
	while (true) {
		/* west-east */
		while (++j <= east) m[i][j] = count++;
		north++; j--;
		if (north > south) break;
		/* north-south */
		while (++i <= south) m[i][j] = count++;
		east--; i--;
		if (east < west) break;
		/* east-west */
		while (--j >= west) m[i][j] = count++;
		south--; j++;
		if (south < north) break;
		/* south-north */
		while (--i >= north) m[i][j] = count++;
		west++; i++;
		if (west > east) break;
	} // end while true
	print_matrix(m, x, y);

	for (int n = 0; n < x; n++) free(m[n]);
	free(m);
	return 0;
}

