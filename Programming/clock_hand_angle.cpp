#include <stdio.h>

/*
 * Give a time of day in formate ##:##, accepting 24 hour clock formats,
 * determine the angle between the hands of the given time in an analogue clock.
 * The hour hand's position will have precision of minutes.
 *
 */

#define abs(a) (a < 0 ? -a : a)
#define round2(a) (int(a * 100) / 100.0)

int main(void) {
	char* ch[3], cm[3];
	int h, m;
	int difference;
	double float angle;
	while (scanf("%2c:%2c", ch, cm) != EOF) {
		ch[2] = cm[2] = 0;
		h = atoi(ch);
		m = atoi(cm);
		if (h > 24 || m >= 60) {
			printf("no valid time\n");
			continue;
		}
		h %= 24;
		h = h * 5 + m / 5;
		difference = abs(h - m);
		difference = diference > 30 ? 60 - diference : diference;
		angle = difference * 180.0 / 30.0;
		printf("%.2lf degrees\n", difference);
	}
}