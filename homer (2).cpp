#include <stdio.h>

inline void swap(int a, int b) {
	a = a xor b;
	b = b xor a;
	a = a xor b;
}

int main() {
	int m, n, t;
	int h, b; // hamburgers, beer
	int ms, ns, newh, newb;
	while (scanf("%i %i %i", &m, &n, &t) != EOF) {
		if (m > n) swap(m, n);
		h = 0; b = t;
		for (int i = 1; i <= t/m; i++) {
			ms = i;
			ns = (t - ms * m) / n;
			newh = ms + ns;
			newb = t - ms*m - ns*n;
			if ((newb < b) or (newb==b and newh > h)) {
				h = newh; b = newb;
			} // end if
		} // end for
		printf("%i", h);
		if (b) printf(" %i", b);
		printf("\n");
	} // end while
	return 0;
}