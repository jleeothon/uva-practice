#include <stdio.h>


char* ttt[3][3];

int main() {

	while (scanf("%3c\n%3c\n%3c", ttt[0], ttt[1], ttt[2]) != EOF) {
		if (
			ttt[0][0] == ttt[0][1] == ttt[0][2] ||
			ttt[1][0] == ttt[1][1] == ttt[1][2] ||
			ttt[2][0] == ttt[2][1] == ttt[2][2] ||
			ttt[0][0] == ttt[1][0] == ttt[2][0] ||
			ttt[0][1] == ttt[1][1] == ttt[2][1] ||
			ttt[0][2] == ttt[1][2] == ttt[2][2] ||
			ttt[0][0] == ttt[1][1] == ttt[2][2] ||
			ttt[0][2] == ttt[1][1] == ttt[2][0]
			) {
			printf("there is a win");
		} else {
			printf("there is no win");
		}
	}
}