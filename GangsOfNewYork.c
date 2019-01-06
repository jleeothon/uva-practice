#include <stdio.h>

int t; // tests

int n; // points

int i, j, k;

typedef struct {
	int x;
	int y;
} point;

int dx, dy;

point points[100];

int l, h;
int lower(int a, int b) {
	return a < b ? a : b;
}
int higher(int a, int b) {
	return a > b ? a : b;
}
int fixx;

// for function
double m, b;

#define funct(x) (b + m * x)
#define ceil(x) (x==floor(x) ? x : x+1)
#define floor(x) ((int)x)

int total;

int main() {
	scanf("%i\n", &t);
	while (t--) {
		total = 0;
		int city[100][100] = {{0}};
		// read all points
		scanf("%i\n", &n);
		for (i = 0; i < n; i++) {
			scanf("%i %i\n", &(points[i].x), &(points[i].y));
		}
		// start!
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j) continue;
				// horizontal line : do nothing
				dy = points[i].y - points[j].y;
				if (!dy) continue;
				dx = points[i].x - points[j].x;
				// diagonal line : paint the line
				if (dx) {
					m = ((double)dy) / dx;
					b = points[i].y - m * points[i].x;
					l = lower(points[i].x, points[j].x);
					h = higher(points[i].x, points[j].x);
					for (k = l; k <= h; k++) {
						city[floor(funct(x))][k] = 1;
						city[ceil(funct(x))][k] = 1;
					}
				// vertical line : paint the line
				} else {
					l = lower(points[i].y, points[j].y);
					h = higher(points[i].y, points[j].y);
					fixx = points[i].x;
					for (k = l; k <= h; k++) {
						city[k][fixx] = 1;
					}
				}
			} // end for every other node
		} // end for every node
		// count them!
		for (i = 0; i < 101; i++) {
			j = 0; while (!city[i][j] && j < 101) j++;
			k = 101; while (!city[i][k] && k>j) k--;
			
		} // for every row
	}
	return 0;
}
