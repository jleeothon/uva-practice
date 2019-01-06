/*
 * P401_Palindromes.c
 *
 *  Created on: 9 Mar 2012
 *      Author: kayin-std
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ismirror(char a, char b) {
	switch (a) {
	case 'A': case 'H': case 'I': case 'M': case 'O': case 'T': case 'U':
	case 'V': case 'W': case 'X': case 'Y': case '1': case '8':
		return a == b;
		break;
	case 'E': return b == '3'; break;
	case 'L': return b == 'J'; break;
	case 'S': return b == '2'; break;
	case 'Z': return b == '5'; break;
	case '2': return b == 'S'; break;
	case '3': return b == 'E'; break;
	case '5': return b == 'Z'; break;
	default: return 0; break;
	}
	return 0;
}

int main() {
	char *s;
	int p, m;
	char *b, *e;
	char results[4][35] = {" -- is not a palindrome.", " -- is a regular palindrome.",
	" -- is a mirrored string.", " -- is a mirrored palindrome."};
	char *message;
	while (scanf("%s", s) != EOF) {
		b = s;
		e = b + strlen(s) - 1;
		p = m = 1;
		while (b<=e && (p||m)) {
			if (*b != *e) p = 0;
			if (!ismirror(*b, *e)) m = 0;
			b++;
			e--;
		}
		if (p&&m) message = results[3];
		else if (p) message = results[1];
		else if (m) message = results[2];
		else message = results[0];
		printf("%s%s\n\n", s, message);
	}
	return 0;
}
