#include <stdio.h>
#include <stdlib.h>

#define abs(a) (a > 0 ? a : -a)

int main() {
	bool jolly;
	int diff;
	unsigned int n;
	int a, b;
	unsigned int i;
	while (true) {

		//puts("CASE");
		bool diffs[3000] = {false};
		jolly = true;
		if (scanf("%u %i", &n, &a) == EOF) break;
		for (i = 1; i < n; i++) {
			scanf("%i", &b);
			diff = a - b;
			diff = abs(diff);
			//printf("a, b, diff: %i, %i, %u\n", a, b, diff);
			if (diff > n-1 || diffs[diff]) {
				jolly = false;
				goto get_rest_of_the_line;
			} else {
				diffs[diff] = true;
			}
			a = b;
		}
		goto analyze;

		get_rest_of_the_line:
		while (getchar() != '\n');
		goto show_results;
		
		analyze:
		for (i = 1; i < n; i++) {
			if (!diffs[i]) {
				jolly = false;
				break;
			}
		}
		show_results:
		if (jolly) puts("Jolly");
		else puts("Not Jolly");
	}

}