#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int t;
int totDices, nFaces;
int djDices, djNumber, wtDices, wtNumber;

double djProb, wtProb;

// combinations taking r out of m items
inline int combination(int m, int r) {
	int c = 1, i;
	for (i = m-r+1; i <= m; i++) {
		c *= i;
		if (r)
			if (c % r) continue;
			else c /= r--;
		else
			break;
	} // end for i[m-r, m]
	for (i; i <= m; i++)
		c *= i;
	while (r)
		c /= r--;
	return c;
} // end int combination

// permutations taking r out of m items
inline int permutation(int m, int r) {
	int c = 1;
	for (int i = m-r; i <= m; i++) {
		c *= i;
	} // end for i[m-r, m]
	return c;
} // end int permutation

double prob(double *pr, int dices, double succProb) {
	*pr = 	combination(totDices, dices) *
			pow(1.0/nFaces, dices) *
			pow(1 - 1.0/nFaces, nDice-dices);

}

/*
 * binomial prob'ty for n successes out of N tries
 * with p success rate in each try.
 */
double binomial(double p, int n, int N) {
	return combination(N, n) * (pow(p, n)) * (pow(1-p,N-n));
}


/*
 * binomial probability for n or more successes
 * out of N tries
 * with p sucess rate in each try.
 */
double binomial2(double p, int n, int N) {
	double b = 0;
	for (int i = n; i <= N; i++) {
		b += binomial(p, n, N);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n%d %d %d %d\n",
				&totDices, &nFaces,
				&djDices, &djNumber,
				&wtDices, &wtNumber);
		double succProb = 1.0 / nFaces;

	} // end while t

	return 0;
}
