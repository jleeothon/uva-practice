#include <stdio.h>


int main() {
	long long int n;
	while (scanf("%lld", &n), n >= 0) {
		n = (n * (n + 1) >> 1) + 1
		printf("%lld\n", n);
	}
	return 0;
}
