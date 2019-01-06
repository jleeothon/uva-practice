#include <ctype.h>
#include <stdio.h>

void reverseWords(char* s) {
	char *a, *b, *c, d;
	c = a = s;
	while (*a) {
		b = a;
		while ((d = b[1]) && !isspace(d)) {
			b++;
		}
		c = b + 1;
		while (b > a) {
			*b ^= *a, *a ^= *b, *b ^= *a;
			b--;
			a++;
		}
		if (*c) {
			a = c + 1;
		} else {
			return;
		}
	}
}

int main() {
	char s[] = "abc def ghi";
	reverseWords(s);
	printf("%s\n", s);
	return 0;
}

