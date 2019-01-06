#include <stdio.h>

int t, i, a, b, n;

int main() {
	scanf("%d\n", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d\n%d", &a, &b);
		if (!(a & 1)) a++;
		if (!(b & 1)) b--;
		n = (b - a) / 2 + 1;
		printf("Case %d: %d\n", i, (int)(n/2.0*(a+b)));
	}
	return 0;
}