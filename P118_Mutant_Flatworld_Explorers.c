#include <stdio.h>

int urx, ury; /* upper-right coordinates */
int x, y; /* x, y of robot */
char o;
int xborder[2][50]={{0},{0}}, yborder[2][50]={{0},{0}};
char instruction;
int death;

char turnright() {
	return o=='N' ? 'E' : o=='E' ? 'S' : o=='S' ? 'W' : 'N';
}

char turnleft() {
	return o=='N' ? 'W' : o=='W' ? 'S' : o=='S' ? 'E' : 'N';
}

void forward() {
	if (o=='N' && !(y==ury && yborder[1][y]))
		y--;
	else if (o=='E' && !(x==urx &&))
		x++;
	else if (o=='S' && y!=0 && !)
	}
}

void checkdeath() {
	if (x < 0) {
		x++;
		xborder[0][x]++;
		death++;
	} else if (x > urx) {
		x--;
		xborder[1][x]++;
		death++;
	}
	if (y < 0) {
		y++;
		yborder[0][y]++;
		death++;
	}
	else if (y > ury) {
		y--;
		yborder[1][y]++;
		death++;
	}
}

int main() {
	scanf("%i %i", &urx, &ury);
	while (scanf("%i %i %c", &x, &y, &o) != EOF) {
		scanf("%c", &instruction);
		printf("%i", (int)instruction);
		scanf("%c", &instruction);
		death = 0;
		while (!death && instruction != '\n') {
			switch (instruction) {
			case 'R': o = turnright(); break;
			case 'L': o = turnleft(); break;
			case 'F': forward(); checkdeath(); break;
			default: break;
			}
		}
		if (death) {
			xborder[x]++; yborder[y]++;
		}
		printf("%i %i %s\n", x, y, death?"LOST":"");
	}
	return 0;
}
