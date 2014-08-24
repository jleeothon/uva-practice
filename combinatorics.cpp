#include <stdio.h>

int combination(int r, int m) {
	int c = 1;
	int i;
	printf("start r=%d m=%d m-r=%d\n", r, m, m-r);
	for (i = m-r+1; i <= m; i++) {
		c *= i;
		if (r) {
			if (c % r) continue;
			else c /= r--;
		} else {
			break;
		}
	}
	for (i+=1; i <= m; i++) {
		c *= i;
	}
	while (r)
		c /= r--;
	return c;
}

int main() {
	int z = combination(0, 8);
	int a = combination(1, 8);
	int b = combination(2, 8);
	int c = combination(3, 8);
	int d = combination(4, 8);
	int h = combination(5, 8);
	int e = combination(6, 8);
	int f = combination(7, 8);
	int g = combination(8, 8);
	printf("%d\n", z);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", h);
	printf("%d\n", e);
	printf("%d\n", f);
	printf("%d\n", g);
	return 0;
}
