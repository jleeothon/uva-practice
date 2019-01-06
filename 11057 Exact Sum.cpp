#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n; /* number of books */
int bookprices[10000];
int allowance;
int booka; /* first tentative book */
int bookb; /* what other book must cost */
int bookbb; /* tentative book b */
int hi, low;

int main() {
	int i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) scanf("%d", bookprices+i);
		scanf("%d", &allowance);
		std::sort(bookprices, bookprices+n);
		
		if (booka > bookb) booka ^= bookb, bookb ^= booka, booka ^= bookb;
		printf("Peter should buy books whose prices are %d and %d.\n\n", booka, bookb);
	}
	return 0;
}