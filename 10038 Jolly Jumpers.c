#include <stdio.h>
#include <string.h>

unsigned int n, m;
int a, b, diff;
char jolly;
int nums[3000] = {0};

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(nums, 0, 3000*sizeof(int));
		scanf("%d", &a);
		for (m=n-1; m; m--) {
			scanf("%d", &b);
			diff = a - b;
			if (diff < 0) diff = -diff;
			nums[diff] += 1;
			a = b;
		}
		jolly = 1;
		for (m=n-1; m; m--) if (nums[m] != 1) jolly = 0;
		if (jolly) puts("Jolly");
		else puts("Not jolly");
	}
	return 0;
}