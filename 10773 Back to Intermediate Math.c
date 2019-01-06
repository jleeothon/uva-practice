#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int T, t;
double d, v, u, t1, t2;

int main() {
	scanf("%d", &T);
	for (t=1; t<=T; t++) {
		scanf("%lf %lf %lf", &d, &v, &u);
		if (u <= v) {
			printf("Case %d: can't determine\n", t);
			continue;
		}
		t1 = d / u;
		t2 = d / (u*sin(acos(v/u)));
		printf("Case %d: %.3lf\n", t, fabs(t1-t2));
	}
	return 0;
}