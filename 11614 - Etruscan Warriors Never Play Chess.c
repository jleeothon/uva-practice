#include <stdio.h>
#include <math.h>

int n;
double m;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%lf", &m);
		printf("%d\n", (int)(sqrt(2*m+0.25)-0.5));
	}
	return 0;
}

/*

n = floor (sqrt(2*Sum + 1/4) - 1/2)

*/