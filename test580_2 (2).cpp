#include <stdio.h>

int main() {
	char line[8];
	while (gets(line) != 0) {
		int count = 0;
		for (int i = 0; i < 7; i++) {
			if (line[i] == '1') count++;
			else count = 0;
			if (count == 3) {
				puts(line);
				break;
			}
		}
	}
	return 0;
}
