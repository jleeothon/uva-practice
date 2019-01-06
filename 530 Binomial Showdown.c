#include <stdio.h>

unsigned long long int n, k, showdown;
unsigned long long int a, b, c;

int gcd(int x, int y) {
	if (x < y) x ^= y, y ^= x, x ^= y;
	int z;
	while (1) {
		z = x % y;
		if (!z) break;
		x = y;
		y = z;
	}
	return y;
}

int main() {
	while (scanf("%d %d", &n, &k) != EOF && n && k) {
		showdown = 1;
		a = n;
		b = n - k;
		if (b > k) {
			c = k;
		} else {
			c = b;
			b = k;
		}
		while (a > b || c) {
			if (c && !(showdown%c)) showdown /= c--;
			if (a > b) showdown *= a--;
			printf("show: %llu, a = %llu, c = %llu\n", showdown, a, c);
		}
		printf("%llu\n", showdown);
	}
	return 0;
}