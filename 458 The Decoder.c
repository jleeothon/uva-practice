// 458 - The Decoder

#include <stdio.h>
char c;
int main() {
	const int shift = '*' - '1';
	while (scanf("%c", &c) != EOF)
		if (c != '\n') putchar(c + shift);
		else putchar('\n');
	return 0;
}