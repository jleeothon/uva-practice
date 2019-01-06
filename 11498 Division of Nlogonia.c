#include <stdio.h>

int k, n, m, x, y;

int main() {
	while (scanf("%d", &k) && k) {
		if (scanf("%d %d", &n, &m) != 2) break;
		while (k-- && scanf("%d %d", &x, &y) == 2) {
			if (x == n || y == m)
				puts("divisa");
			else if (x < n)
				if (y < m) puts("SO");
				else puts ("NO");
			else
				if (y < m) puts("SE");
				else puts("NE");
		}
	}	
	return 0;
}