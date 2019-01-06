#include <stdio.h>
#include <ctype.h>

char c;
int count;
int reading = 0;

int main() {
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			printf("%d\n", count);
			count = reading = 0;
		} else if (isalpha(c)) {
			reading = 1;
			continue;
		} else {
			if (reading) count += 1;
			reading = 0;
		}
	}
	if (count) {
		printf("%d\n", count);
	}
	return 0;
}