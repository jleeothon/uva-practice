#include <stdio.h>

int tests, freq, amp;

#define putn(x) putchar((x)+'0');

int main() {
	scanf("%d", &tests);
	int i, j;
	while (tests--) {
		scanf("%d\n%d", &amp, &freq);
		while (freq--) {
			for (i = 1; i <= amp; i++) {
				j = i;
				while (j--) putn(i);
				putchar('\n');
			}
			i = amp - 1;
			do {
				j = i;
				while (j--) putn(i);
				putchar('\n');
			} while (--i);
			puts("\n\n");
		}
	}
	return 0;
}