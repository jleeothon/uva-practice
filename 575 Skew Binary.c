#include <stdio.h>
#include <math.h>

char sbin[105];
char *sb;
int number;
int i;

#define ctoi(c) ((int)((c)-'0'))

int main() {
	while (scanf("%s", sbin)) {
		sb = sbin;
		while (*sb != '\0') sb++;
		sb--;
		if (!(sb - sbin) && (*sb == '0')) return 0;
		i = 1;
		number = 0;
		while (sb >= sbin) {
			if (ctoi(*sb)) number += ctoi(*sb)*(pow(2, i)-1);
			i += 1;
			sb --;
		}
		printf("%d\n", number);
	}
	return 0;
}