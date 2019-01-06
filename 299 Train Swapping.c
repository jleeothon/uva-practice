#include <stdio.h>

int L, T;
int c[51];
int count;

int bubble_sort() {
	static int i = 0, j = 0;
	count = 0;
	for ( i = L-1; i > 0; i-- ) for ( j = 0; j < i; j++ )
		if (c[j] > c[j+1]) {
			c[j] ^= c[j+1], c[j+1] ^= c[j], c[j] ^= c[j+1];
			count ++;
		}
}

int main() {
	int i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &L);
		for (i=0; i<L; i++) scanf("%d", c+i);
		bubble_sort();
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}