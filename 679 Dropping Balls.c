#include <stdio.h>
#include <math.h>

int t, depth, ith;
int leaves[524288];
int i;
int leafc;
int sum;


int main() {
	scanf("%d", &t);
	*leaves = 0;
	while (t--) {
		scanf("%d %d", &depth, &ith);
		leafc = pow(2, depth-1);
		sum = (1 - pow(2, depth-1)) / (1 - 2);
		ith -= 1;
		for (i = 1; i < leafc; i++) {
			leaves[i] = i&1 ? (leaves[i-1]+leafc/2) : (leaves[i/2]/2);
		}
		for (i = 0; i < leafc; i++) if (leaves[i] == ith) break;
		printf("%d\n", (sum+i+1));
	}
	return 0;
}