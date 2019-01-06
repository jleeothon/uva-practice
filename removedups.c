#include <string.h>
#include <stdio.h>



int a[10][5];
a[3][2];
*(a+3*5+2);

int **a;
a[3][2];
*(*(a+3) + 2)

void removedups0(char *s) {
	int length = strlen(s);
	char *a = s;
	while (*a) {
		if (a[0] == a[1]) {
			memmove(a, a + 1, length);
		} else {
			a += 1;
			length -= 1;
		}
	}
}

void removedups(char *s) {
	char *a, *i, c;
	a = i = s;
	while ((c = *i)) {
		if (c != i[1]) {
			*a++ = c;
		}
		i += 1;
	}
	*a = '\0';
}

int main() {
	char a[] = "AA BBB CC DDDD     EEE";
	removedups(a);
	printf("%s\n", a);
	return 0;
}
