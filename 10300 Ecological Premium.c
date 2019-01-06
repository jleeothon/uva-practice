#include <stdio.h>

int n, f;
int farmsize, animals, greenness;
int premiums;

int main() {
	/* por cada caso */
	scanf("%d", &n);
	while (n--) {
		/* resetear el total por cada caso de prueba */
		premiums = 0;
		/* por cada granjero */
		scanf("%d", &f);
		while (f--) {
			scanf("%d %d %d", &farmsize, &animals, &greenness);
			/*
			recordar que por cada animal recibe:
				tierra / animales * factor_de_amigable_medioambiente
			y esto se multiplica por cada animal
			se simplifican los números!
			*/
			premiums +=  greenness * farmsize;
		}
		printf("%d\n", premiums);
	}
}