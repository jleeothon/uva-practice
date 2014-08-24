#include <stdio.h>
#include <string.h>
#include <math.h>

int x[1000000];
int calculated[1000000];

double sin2(int n) {
	double s = sin(n);
	return s*s;
}

void set_x(int i) {
	int j = (int)(i - sqrt(i));
	int k = (int)(log(i));
	int l = (int)(i*sin2(i));
	if (!calculated[j]) set_x(j);
	if (!calculated[k]) set_x(k);
	if (!calculated[l]) set_x(l);
	x[i] = (x[j] + x[k] + x[l])%1000000;
	calculated[i] = 1;
}


int main() {
	memset(calculated, 0, 1000000*sizeof(int));
	x[0] = 1;
	calculated[0] = 1;
	int i;
	while (1) {
		scanf("%d", &i);
		if (i == -1) break;
		if (!calculated[i]) {
			set_x(i);
		}
		printf("%d\n", x[i]);
	}
	return 0;
}