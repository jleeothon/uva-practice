/*
 * WHAT'S THE FREQUENCY, KENNETH
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char line[128];
	
	int maxfreq;

	while (scanf("%s", line) != EOF) {
		char *c = line;
		int freqs[42] = {0};
		char modes[42] = {NULL};
		maxfreq = 0;
		int nextm = 0;
		while (*c != NULL) {
			if (!isalpha(*c)) continue;
			int position = *c-'A';
			freqs[position]++;
			if (freqs[position] == maxfreq) {
				modes[nextm++] = *c;
				modes[nextm] = NULL;
			} else if (freqs[position] > maxfreq) {
				maxfreq = freqs[position];
				*modes = *c;
				*(modes+1) = NULL;
			}
			c++;
		}


	}
}

