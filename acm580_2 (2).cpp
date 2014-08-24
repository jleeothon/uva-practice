// acm580_2.cpp

#include <stdio.h>

unsigned int uranium[31], tribonacci[31];

void tribonaccify(void);
void uranify(void);

int main() {

	uranium[0] = 0;
	tribonacci[0] = 0;
	tribonacci[1] = 0;
	tribonacci[2] = 1;
	tribonaccify();
	uranify();

	puts("unsigned int uranium[] = {");
	for (int i = 0; i <= 30; i++) {
		printf("%u,\n", uranium[i]);
	}
	puts("};");

}

void tribonaccify() {
	for (int i = 3; i <= 30; i++) {
		tribonacci[i] =
			tribonacci[i-1] + tribonacci[i-2] + tribonacci[i-3];
	}
}

void uranify() {
	for (int i = 1; i <= 30; i++) {
		uranium[i] = 2 * uranium[i-1] + tribonacci[i-1];
	}
}