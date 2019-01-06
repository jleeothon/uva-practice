
#include <stdio.h>
#include <math.h>

int is_palindrome(long int num) {
	static int ipi = 0;
	static int ipj = 0;
	static int p10 = 0;
	p10 = (int) log10(num);
	p10 = (int) pow(10, p10);
	while (p10 > 1) {
		ipj = num % 10;
		ipi = num / p10;
		if (ipj != ipi) return 0;
		num -= ipi * p10;
		num /= 10;
		p10 /= 100;
	}
	return 1;
}

long int reverse_add(long int num) {
	long int cop = num;
	long int rev = 0;
	while (cop > 0) {
		rev = rev * 10 + cop % 10;
		cop /= 10;
	}
	return rev + num;
}

int N;
long int P;
int itercount;
int main() {
	scanf("%d\n", &N);
	while (N--) {
		scanf("%ld", &P);
		itercount = 0;
		while (!is_palindrome(P)) {
			itercount += 1;
			P = reverse_add(P);
		}
		printf("%d %ld\n", itercount, P);
	} /* end while */
	return 0;
}