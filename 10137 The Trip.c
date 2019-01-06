#include <stdio.h>

float students[1000];
float superavit;
float deficit;
float average;

float difference;

int n;
int i;

#define round2(money) (((int)(money*100))/100.0)

int main() {	
	while (1) {
		scanf("%i", &n); if (n==0) break;
		average = 0;
		superavit = 0;
		deficit = 0;
		for (i=0; i<n; i++) {
			scanf("%f", students+i);
			average += *(students+i);
		}
		average /= n;
		average = round2(average);
		for (i=0; i<n; i++) {
			difference = students[i] - average;
			if (difference < 0)
				deficit += difference;
			else
				superavit += difference;
		}
		deficit = deficit < 0 ? -deficit : 0;
		//if (superavit > deficit) puts("superavit"); else puts ("deficit");
		printf("$%.2f\n", superavit > deficit ? deficit : superavit);
	}	
	return 0;
}
