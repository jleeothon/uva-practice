#include <stdio.h>
#include <math.h>

double evaluate(double x);

int p, q, r, s, t, u;

int makeIncreasing = 1;

int main() {

	while (scanf("%i %i %i %i %i %i", &p, &q, &r, &s, &t, &u) != EOF) {

		double y_0 = evaluate(0);
		if (y_0 == 0) { puts("0.0000"); continue; }

		double y_1 = evaluate(1);
		if (y_1 == 0) { puts("1.0000"); continue; }

		double xi = -1, xh = -2;
		double y_xi;
		double hi = 1, lo = 0;

		if (y_0 * y_1 < 0) {
			if (y_0 > y_1) makeIncreasing = -1;
			while (xi != xh) {
				xh = xi;
				xi = (hi + lo) / 2;
				y_xi = evaluate(xi);
				if (y_xi > 0) hi = xi;
				else  if (y_xi < 0) lo = xi;
				else break;
			}
			printf("%.4f\n", xi);
		} else {
			puts("No solution");
		}
	}
	return 0;
}

double evaluate(double x) {
	return makeIncreasing * (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
