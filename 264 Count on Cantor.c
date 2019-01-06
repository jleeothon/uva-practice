#include <stdio.h>
#include <math.h>

int v, n, nftd, offset, cres, dim;

int main() {
	while (scanf("%i", &v) != EOF) {
		n = ceil((sqrt(1+8*v)-1)/2);
		nftd = (n*n-n) /2 + 1;
		offset = v - nftd;
		cres = 1 + offset;
		dim = n - offset;
		printf("TERM %i IS ", v);
		if (n & 1) printf("%i/%i", dim, cres);
		else printf("%i/%i", cres, dim);
		printf("\n");
	}
	return 0;
}
