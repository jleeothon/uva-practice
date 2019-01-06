#include <stdio.h>

int n;
int i;
int a, b, c;
int main() {
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		scanf("%d %d %d", &a, &b, &c);
		i++;
		b = (b+c)%a;
		if (!b) b = a;
		printf("Case %d: %d\n", i, b);
	}
	return 0;
}