
/*
nota: usar macros-como-funciones (function-like macros) es peligroso.
no aprendan malos ejemplos.
no lo hagan.
yo lo hago porque soy chido.
este macro obtiene el valor absoluto de un número.
*/

#include <stdio.h>
#include <math.h>

int main() {
	double a, b;
	while (scanf("%lf %lf", &a, &b) == 2) {
		printf("%.0lf\n", fabs(a-b));
	}
	return 0;
}