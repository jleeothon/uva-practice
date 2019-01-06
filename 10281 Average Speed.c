#include <stdio.h>
#include <stdlib.h>

char reading[100];
int hh, mm, ss, kmh, oldkmh;
double lastt, newt, deltat;
double totald;

int main() {
	int nread;
	lastt = totald = 0;
	oldkmh = kmh = 0;
	while (gets(reading), !feof(stdin)) {
		nread = sscanf(reading, "%02d:%02d:%02d %d", &hh, &mm, &ss, &kmh);
		newt = ss + 60*mm + 3600*hh;
		deltat = newt - lastt;
		totald += deltat / 3600.0 * oldkmh;
		if (nread == 3) printf("%02d:%02d:%02d %.2lf km\n", hh, mm, ss, totald);
		lastt = newt;
		oldkmh = kmh;
	}
	return 0;
}