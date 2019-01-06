#include <stdio.h>


unsigned int m, r, a, b, c, bb;

int main() {

	while (scanf("%u %u", &m, &r), m || r) {
		a = m - r;
		b = r;
		if (a < b) a ^= b, b ^= a, a ^= b;
		a += 1;
		c = 1;
		bb = 1;
		while (a <= m || bb <= b) {
			printf("a=%u, bb=%u, c=%u\n", a, bb, c);
			printf("c %% bb %u\n", c % bb);
			if (bb <= b && !(c % bb)) {
				printf("c /= bb %u\n", c / bb);
				c = c / bb;
				printf("c %u\n", c);
				bb += 1;
			}
			if (a <= m) {
				c *= a;
				a += 1;
			}
			printf("a=%u, bb=%u, c=%u\n", a, bb, c);
			pause("")
		}
		printf("%u\n", c);
	}

	return 0;
}