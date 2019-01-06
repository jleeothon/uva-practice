// 594

#include <stdio.h>
#include <stdlib.h>

int orig;
int inv;
char *b0;
char *b1;
char *b2;
char *b3;

int main() {
	while (scanf("%d\n", &orig) != EOF) {
		inv = orig;
		b0 = (char*) &inv;
		b1 = b0 + 1;
		b2 = b1 + 1;
		b3 = b2 + 1;
		*b0 ^= *b3;
		*b3 ^= *b0;
		*b0 ^= *b3;
		*b1 ^= *b2;
		*b2 ^= *b1;
		*b1 ^= *b2;
		printf("%d converts to %d\n", orig, inv);
	}
	return 0;
}