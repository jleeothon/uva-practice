#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ages[101];
int n;
int i;
int age;

int main() {

	while(1) {
		scanf("%d\n", &n);
		if (!n) return;
		memset(ages, 0, n*sizeof(int));
		for (i=1; i<=n; i++) {
			scanf("%d", &age);
			ages[age] += 1;
		}
		i = 1;
		while (!ages[i]) i += 1;
		printf("%d", i);
		ages[i] -= 1;
		while (ages[i]) {
			printf(" %d", i);
			ages[i] -= 1;
		}
		for (i+=1; i<=n; i++) {
			while (ages[i]) {
				printf(" %d", i);
				ages[i] -= 1;
			}
		}
		printf("\n");
	}
	return 0;
}