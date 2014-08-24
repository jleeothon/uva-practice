#include <stdio.h>

char c;
char buffer[100];
unsigned int count;


int main() {
	c = 0;
	while (true) {
		if (c = getc() == EOF) break;
		if (isalnum(c)) {
			buffer[count++] = c;
			buffer[count] = NULL;
		} else if (isblank(c)) {
			if (count == 3 &&
					isalpha(buffer[0]) &&
					isdigit(buffer[1]) && isdigit(buffer[2])) {
				printf("***%c", c);
			} else {
				printf("%s%c", buffer, c);
			}
		}

	}
	return 0;
}