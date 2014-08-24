/*
 * Menu.h
 *
 *  Created on: 22 Feb 2012
 *      Author: kayin-std
 */

#ifndef MENU
#define MENU
#include <stdio.h>
#include <stdarg.h>

int menu(int quantity, char* prompt, char * options, ...) {
	va_list op;
	va_start(op, options);
	char* c = options;
	int i = 1;
	int q = quantity;
	while (q--) {
		printf("%-3i\t%s\n", i, c);
		i++;
		c = va_arg(op, char*);
	}
	va_end(op);

	int choose;
	do {
		printf("%s", prompt);
		scanf("%i", &choose);
	} while (choose < 1 || choose > quantity);
	return choose;
}

#endif /* MENU */
