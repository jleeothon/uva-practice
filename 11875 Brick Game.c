#include <stdio.h>
#include <stdlib.h>

unsigned short int T, N, n, i, j, k, r;

int main() {
	scanf("%hu", &T);
	for (i=1; i<=T; i++) {
		scanf("%hu", &N);
		n = N / 2;
		while (n--) scanf("%hu", &k);
		scanf("%hu", &r);
		n = N / 2;
		while (n--) scanf("%hu", &k);
		printf("Case %hu: %hu\n", i, r);
	}
	return 0;
}