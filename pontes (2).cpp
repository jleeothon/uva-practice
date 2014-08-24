#include <stdio.h>
typedef unsigned int natural;

bool sum(natural, natural);

natural R; // 2 <= R <= 100
natural K; // 1 <= K R*(R-1)/2; i.d. 4950
natural regiones[100+1];

int main() {
	natural r1, r2;
	while (true) {
		if (scanf("%u %u", &R, &K) == EOF) break;
		for (natural i = 1; i <= R; i++) regiones[i] = 0;
		for (natural i = 0; i < K; i++) {
			scanf("%u %u", &r1, &r2);
			regiones[r1]++;
			regiones[r2]++;
		}
		for (natural i = 1; i <= R; i++) {
			//printf("-- %d\n ", i);
			if (sum(i, 0)) {
				puts("S");
				goto end;
			}
		}
		puts("N");
		end:;
	} // end while true
	return 0;
}

bool sum(natural next, natural accum) {
	accum = accum + regiones[next];
	//printf("accum %d\n", accum);
	if (accum > K) return false;
	else if (accum == K) return true;
	for (natural i = next+1; i <= R; i++) {
		//printf("%d ", i);
		if (sum(i, accum)) return true;
	}
	return false;
}