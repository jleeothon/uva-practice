
#include <stdio.h>

int main() {
	unsigned int a, b;
	while (scanf("%u %u", &a, &b) == 2) {
		if (a < b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		printf("%u\n", (a-b));
	}
	return 0;
}



