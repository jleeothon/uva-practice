#include <stdio.h>
#include <stdlib.h>

/*
Receives a number n followed by a list of n numbers.
The program is queried for the smalled one between the ith and the jth element
where elements are counted from 0.
*/

int n;
int numbers[500];

int sTreeM[1024]; // segment tree minimum
int sTreeS[1024]; // segment tree start
int sTreeE[1024]; // segment tree end

int i;
int j;

int greaterPowerOfTwo(int num) {
	int p = 1;
	while (p < num) p <<= 1;
	return p;
}

void arrayIndexOfTreeIndex(int i) {
	while (i > n) {
		if (i & 1) {
			i = (i - 2) / 2;
		}
	}
}

/* parameters: index, start, end*/
void build_tree(int i, int s, int e) {
	sTreeS[i] = s;
	sTreeE[i] = e;
	if (s == e) {
		sTreeM = 
	}
}

int main() {

	scanf("%d", &n);
	if (n > 500) {
		perror("cannot process more than 500 numbers");
		exit(0);
	}

	i = n;
	while (i--) {
		scanf("%d", numbers + i);
	}



	return 0;
}