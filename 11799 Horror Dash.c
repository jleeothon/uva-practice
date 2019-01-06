#include <stdio.h>

int T, N;
int t, n, m, max;

int main() {
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		max = -1; // sabemos que nadie va a vel. negativa
		while (N--) {
			scanf("%d", &m);
			if (m > max) max = m;
		}
		printf("Case %d: %d\n", t, max);
	}
	return 0;
}