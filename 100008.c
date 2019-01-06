
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct letraocurrencia {
	char letra;
	int ocurrencias;
};


struct letraocurrencia letraocurrencias[30];

int numlineas;
char c;

int comp(const void* a, const void* b) {
	struct letraocurrencia aa = *((struct letraocurrencia*) a);
	struct letraocurrencia bb = *((struct letraocurrencia*) b);
	if (aa.ocurrencias != bb.ocurrencias) {
		return bb.ocurrencias - aa.ocurrencias;
	} else {
		return aa.letra - bb.letra;
	}
}

int main() {

	scanf("%d", &numlineas);
	int i;
	for (i = 0; i < 30; i++) {
		letraocurrencias[i].letra = 'A' + i;
		letraocurrencias[i].ocurrencias = 0;
	}

	while (scanf("%c", &c) != EOF) {
		c = toupper(c);
		if (isalpha(c)) {
			letraocurrencias[c-'A'].ocurrencias ++;
		}
	}

	qsort(letraocurrencias, 26, sizeof(struct letraocurrencia), comp);

	for (i = 0; i <= 26; i++) {
		if (letraocurrencias[i].ocurrencias == 0) break;
		printf("%c %d\n", letraocurrencias[i].letra, letraocurrencias[i].ocurrencias);
	}

	return 0;
}