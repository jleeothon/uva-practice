#include <string.h>
#include <stdio.h>

int n;
char st[101];
int l; /* longitud total */
int i, j, k;
int gl; /* longitud de grupo */
char t; /* variable temporal */

int main() {

	while(scanf("%d %s", &n, st) == 2) {
		l = strlen(st);
		gl = l / n;
		for (k = 0; k < n; k++) {
			i = gl * k;
			j = i + gl - 1;
			while (i < j) {
				/* intercambio normalito */
				/*t = st[i];
				st[i] = st[j];
				st[j] = t;*/
				/* intercambio binario */
				st[i] ^= st[j];
				st[j] ^= st[i];
				st[i] ^= st[j];
				/* intercambio aritmético */
				/*st[i] += st[j];
				st[j] = st[i] - st[j];
				st[i] -= st[j];*/
				/* mover i, y j */
				i += 1; j -= 1;
			}
		} /* end for */
		printf("%s\n", st);
	}

	return 0;
}
