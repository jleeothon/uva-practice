#include <stdio.h>

char s[10];
int a, b;
double HH, MM, angle;

#define angleH(h, m) ((h)*30.0+(m)/2.0)
#define angleM(m) (m*6)

void calc_angle() {
	angle = HH - MM;
	if (angle < 0.0) angle = -angle;
	if (angle > 180.0) angle = 360 - angle;
}

int main() {
	while (gets(s), !feof(stdin)) {
		sscanf(s, "%d:%02d", &a, &b);
		if (!(a || b)) break;
		HH = (double)(a%12), MM = (double)(b%60);
		HH = angleH(HH, MM);
		MM = angleM(MM);
		calc_angle(HH, MM);
		printf("%.3lf\n", angle);
	}
	return 0;
}