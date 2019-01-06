#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238462643383279
#define sqrt2 1.41421356237

double s, rads, arc, chord;
char units[4];


int main() {
	while (scanf("%lf %lf %s\n", &s, &rads, units) != EOF) {
		s += 6440;
		if (*units == 'm') rads /= 60;
		rads = rads * PI / 180.0;
		if (rads > PI) rads = 2 * PI - rads;
		arc = s * rads;
		chord = sqrt2 * s * sqrt(1-cos(rads));
		printf("%.6lf %.6lf\n", arc, chord);
	}
	return 0;
}
