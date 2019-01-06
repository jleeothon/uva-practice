#include <stdio.h>

char c;
int isrect[11];
double a[11], b[11], c[11], d[11];

unsigned int i, count;

int main() {

	for (i=1; i<=10; i++) {
		scanf("%c", &c);
		if (c == 'r') {
			isrect[i] = 1;
			scanf("%lf %lf %lf %lf\n", a+i, b+i, c+i, d+i);
		} else if (c == 'c') {
			isrect[i] = 0;
			scanf("%lf %lf %lf\n", a+i, b+i, c+i);
		} else {
			i -= 1;
			break;
		}
		
	}

	return 0;
}