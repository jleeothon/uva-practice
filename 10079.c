/*
 * 10079
 * Pizza Cutting
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1020
 * Johnny Lee
 */

#include <stdio.h>

int main() {
	long long int n;
	while (scanf("%lld", &n), n >= 0) {
		n = (n * (n + 1) >> 1) + 1;
		printf("%lld\n", n);
	}
	return 0;
}
