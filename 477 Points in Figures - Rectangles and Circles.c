#include <stdio.h>
#include <stdlib.h>

struct figure {
	char type;
	union {
		struct {
			double x1, x2, y1, y2;
		} r;
		struct {
			double x, y, sr;
		} c;
	} u;
} figures[11];

int has_point(struct figure* f, double x, double y) {
	static double d = 0;
	switch (f->type) {
		case 'r':
			if (x > f->u.r.x1 && x < f->u.r.x2 && y < f->u.r.y1 && y > f->u.r.y2) return 1;
			else return 0;
			break;
		case 'c':
			d = (x - f->u.c.x) * (x - f->u.c.x) + (y - f->u.c.y) * (y - f->u.c.y);
			if (d < f->u.c.sr) return 1;
			else return 0;
			break;
		default:
			puts("ERROR ---");
			return 0;
			break;
	}
}

unsigned int figure_count = 0;

unsigned int b, i, j;

double x, y;

int main() {

	for (b=1, i=1; b && i<=10; i++) {
		scanf("%c", &(figures[i].type));
		switch (figures[i].type) {
			case 'r':
				scanf("%lf %lf %lf %lf\n",
					&(figures[i].u.r.x1),
					&(figures[i].u.r.y1),
					&(figures[i].u.r.x2),
					&(figures[i].u.r.y2)
					);
			break;
			case 'c':
				scanf("%lf %lf %lf\n",
					&(figures[i].u.c.x),
					&(figures[i].u.c.y),
					&(figures[i].u.c.sr)
					);
				figures[i].u.c.sr *= figures[i].u.c.sr;
			break;
			case '*':
				b = 0;
			break;
			default: puts("ERROR****"); break;
		}
	} /* end for */
	figure_count = i-2;

	j = 0;
	while (scanf("%lf %lf", &x, &y) != EOF) {
		if (x == 9999.9 && y == 9999.9) break;
		j += 1;
		b = 0;
		for (i=1; i<=figure_count; i++) {
			if (has_point(figures+i, x, y)) {
				printf("Point %u is contained in figure %u\n", j, i);
				b = 1;
			}
		}
		if (!b) {
			printf("Point %u is not contained in any figure\n", j);
		}
	}
	return 0;
}