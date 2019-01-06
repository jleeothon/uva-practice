#include <stdio.h>


char field[101][101];

int n, m;

#define isvalid(i, j) ((i) > -1 && (i) < n && (j) > -1 && (j) < m)

char makechar(int digit) {
	return digit + '0';
}

int countmines(int i, int j) {
	int r = 0;
	r += (isvalid(i-1, j-1) && field[i-1][j-1] == '*');
	r += (isvalid(i-1, j) && field[i-1][j] == '*');
	r += (isvalid(i-1, j+1) && field[i-1][j+1] == '*');
	r += (isvalid(i, j-1) && field[i][j-1] == '*');
	r += (isvalid(i, j+1) && field[i][j+1] == '*');
	r += (isvalid(i+1, j-1) && field[i+1][j-1] == '*');
	r += (isvalid(i+1, j) && field[i+1][j] == '*');
	r += (isvalid(i+1, j+1) && field[i+1][j+1] == '*');
	return r;
}

void putfield() {
	int i, j;
	for (i=0; i<n; i++) {
		puts(field[i]);
	}
}

int main() {

	int i, j, k, fieldn = 0;
	int first = 1;
	while (scanf("%d %d", &n, &m) && n && m) {
		if (!first) putchar('\n');
		else first = 0;
		fieldn += 1;
		for (i=0; i<n; i++) {
			scanf("%s", field[i]);
		}
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (field[i][j]=='.') field[i][j] = makechar(countmines(i, j));
			}
		}
		printf("Field #%d:\n", fieldn);
		putfield();
	}

	return 0;
}