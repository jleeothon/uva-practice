#include <stdio.h>
#include <math.h>

double n, p;

int main() {
	while (scanf("%lf", &n) != EOF) {
		scanf("%lf", &p);
		printf("%.0lf\n", exp(log(p)/n));
	}
	return 0;
}