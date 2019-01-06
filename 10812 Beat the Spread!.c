#include <stdio.h>

unsigned int t, s, d;
int a, b;

int main() {
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d", &s, &d);
		b = (s - d);
		if (b & 1) goto impossible;
		b >>= 2;
		a = s - b;
		if (b >= 0 && a >= b) printf("%d %d\n", a, b);
		else impossible: puts("impossible");
	}
}