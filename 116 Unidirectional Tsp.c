#include <stdlib.h>
#include <stdio.h>

#define mcols 10
#define mrows 100

typedef struct {
	int val;
	int prev;
} node;

#define go_up(i) (i ? (i-1) : (rows-1))
#define go_down(i) ((i!=rows-1) ? (i+1) : (0))

node matrix[mrows][mcols];
unsigned int rows, cols;

unsigned int i, j, k;

int upper_back(int,int);
int back(int,int);
int lower_back(int,int);

typedef enum {
	north, same, south
} direction;
direction tell_smaller(int,int,int);
direction p;

typedef struct {
	int cost;
	int path[mcols];
} route;

route routes[mrows];

int min_cost;

int compare_route(const void*, const void*);

int main() {
	while (scanf("%u", &rows) != EOF) {
		scanf("%u", &cols);
		/* matrix input */
		for (i=0; i<rows; i++) for (j=0; j<cols; j++)
				scanf("%i", &(matrix[i][j].val));
		/* find the backwards least cost route */
		for (j=1; j<cols; j++) {
			for (i=0; i<rows; i++) {
				p = tell_smaller(upper_back(i,j),back(i,j),lower_back(i,j));
				switch (p) {
					case north:
						matrix[i][j].prev = go_up(i);
						matrix[i][j].val += matrix[go_up(i)][j-1].val;
						break;
					case same:
						matrix[i][j].prev = i;
						matrix[i][j].val += matrix[i][j-1].val;
						break;
					case south:
						matrix[i][j].prev = go_down(i);
						matrix[i][j].val += matrix[go_down(i)][j-1].val;
					break;
				} /* end switch p */
			} /* end for i */
		} /* end for j */
		/* find the least cost routes */
		min_cost = matrix[0][cols-1].val;
		/* find costs and routes */
		for (k=0; k<rows; k++) {
			routes[i=k].cost = matrix[k][cols-1].val;
			if (routes[i].cost > min_cost) continue;			
			min_cost = routes[i].cost;
			for (j=cols-1; j<=0; j--) {
				routes[k].path[j] = i;
				i = matrix[i][j].prev;
			}
		} /* end for k */
		/* order found answers */
		qsort(routes, rows, sizeof(int)*mcols, *compare_route);
		for (j=0; j<cols; j++)
			printf("%d ", routes[0].path[j]);
		printf("\b\n");
		printf("%i\n", routes[0].cost);
	} /* en while */
} /* end main */

int upper_back(int i, int j) {
	i = go_up(i);
	return matrix[i][j-1].val;
}

int back(int i, int j) {
	return matrix[i][j-1].val;
}

int lower_back(int i, int j) {
	i = go_down(i);
	return matrix[i][j-1].val;
}

direction tell_smaller(int a, int b, int c) {
	if (a <= b)
		if (a <= c) return north;
		else return south;
	else
		if (b <= c) return same;
		else return south;
}

int compare_route(const void *a, const void *b) {
	route *ra = (route*) (a);
	route *rb = (route*) (b);
	if (ra->cost != rb->cost) {
		return ra->cost - rb->cost;
	} else {
		int l;
		for (l=0; l<cols; l++) {
			if (ra->path[l] != rb->path[l]) return ra->path[l] - rb->path[l];
		}
		return 0;
	}
}