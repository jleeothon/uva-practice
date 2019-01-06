#include <stdio.h>

unsigned short int n;
unsigned short int i;

int ans[20];

int main() {
	scanf("%hu", &n);
	while (1) {
		if (scanf("%d", ans) == EOF) break;;
		for (i=1; i<n; i++) {
			scanf("%d", ans+i);
		}
	}
}