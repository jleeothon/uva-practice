#include <stdio.h>
#include <stdlib.h>

int t; // casos
int d; // fuerza de la bomba
int n; // poblaciones de ratas

int **mapa;

int max_x, max_y, max_p;

void aloja_mapa ( void ) {
	int i;
	mapa = (int**) malloc(1025 * sizeof(int*));
	for (i = 0; i < 1025; i++) {
		mapa[i] = (int*) malloc(1025 * sizeof(int));
	}
}
 	
void resetea_mapa ( void ) {
	int i;
	for (i = 0; i < 1025; i++) {
		memset(mapa[i], 0, 1025*sizeof(int));
	}
}

int existe ( int x, int y ) {
	if ( x >= 0 && x <= 1024 && y >= 0 && y <= 1024 ) return 1;
	else return 0;
}

void encuentra_max ( void ) {
	max_p = max_x = max_y = 0;
	int i, j;
	for (i = 0; i < 1024; i++) {
		for (j = 0; j < 2014; j++) {
			if (mapa[i][j] > max_p) {
				max_x = i;
				max_y = j;
				max_p = mapa[i][j];
			}
		}
	}
} /* encuentra_max */

int main () {

	int x, y, p;
	int i, j, ii, jj;

	scanf("%d\n", &t);

	while (t--) {
		resetea_mapa(mapa);
		scanf("%d\n%d\n", &d, &n);
		while (n--) {
			scanf("%d %d %d", &x, &y, &p);
			for (i=x-d, ii=x+d; i<ii; i++) {
				for (j=y-d, jj=y+d; j<jj; j++) {
					if (existe(i, j)) mapa[i][j] += p;
				} /* end for j */
			} /* end for i */
		} /* end while n */
		encuentra_max();
		printf("%d %d %d\n", max_x, max_y, max_p);
	} /* end while t */

	return 0;
} /* main */