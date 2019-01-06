#include <stdio.h>

int stopcount;
int stops[20001];
int mstarti, mendi, max;


void printstops() {
	int i;
	for (i=0; i<stopcount; i++) {
		printf("%d, ", stops[i]);
	}
	putchar('\n');
}

int main() {

	int tests, ti, sci, scj;
	scanf("%d", &tests);
	for (ti = 1; ti <= tests; ti++) {
		max = -1;
		scanf("%d", &stopcount);
		stopcount -= 1;
		scanf("%d", stops);
		for (sci = 1; sci < stopcount; sci++) {
			scanf("%d", stops+sci);
			stops[sci] += stops[sci-1];
		}
		for (sci = 0; sci < stopcount; sci++) {
			for (scj = sci; scj < stopcount; scj++) {
				if ((stops[scj] - stops[sci] > max) ||
					(stops[scj] - stops[sci]) == max &&
						(scj - sci > mendi - mstarti)
					) {
					max = stops[scj] - stops[sci];
					mstarti = sci;
					mendi = scj;
				}
			}
		}
		printstops();
		printf("max is %d from %d to %d\n", max, mstarti, mendi);
		if (max > 0) {
			printf("The nicest part of route %d is between stops %d and %d\n",
				ti, mstarti+2, mendi+2);
		} else {
			printf("Route %d has no nice parts\n", ti);
		}
	}

	return 0;

}