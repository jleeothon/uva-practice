#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double a, A, B, C;

int main() {
	const double twothirds = 2.0 / 3.0;
	const double k1 = 4 * (1 - PI/6.0 + sqrt(3.0)/4.0);
	/*printf("k1 = %.10lf\n", k1);*/
	while (scanf("%lf", &a) != EOF) {
		C = a * a * k1;
		B = twothirds * (a*a*(2.0-PI/2.0) - C);
		A = a*a - B - C;
		printf("%.3lf %.3lf %.3lf\n", A, B, C);
	}
	return 0;
}