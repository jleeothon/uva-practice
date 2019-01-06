#include <stdio.h>

unsigned long long int fibos[55];
int t, n;

void init_fibos() {
	int i;
	for (i = 2; i < 55; i++) {
		fibos[i] = fibos[i-1] + fibos[i-2];
	}
}

void print_fibos() {
	int i;
	for (i = 0; i < 55; i++) {
		printf("%llu\n", fibos[i]);
	}
}

int main() {
	fibos[0] = fibos[1] = 1;
	init_fibos();
	int  i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d", &n);
		printf("Scenario #%d:\n%llu\n\n", i, fibos[n+1]);
	}
	return 0;
}