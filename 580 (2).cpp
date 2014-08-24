
unsigned int limit;
unsigned int counter;

typedef unsigned int natural;



int main() {
	for (int i = 1; i <= 30; i++) {

	}
}

natural permutate(char *permutation, natural counter, natural limit) {
	static natural count_for_this_limit = 0;
	if (counter < limit) {

	} else {
		natural c = 0;
		for (natural i = 0; i < limit; i++) {
			if (permutation[i] == 'u') c++;
			else c = 0;
			if (c == 3) {
				count_for_this_limit++;
			}
		}
	}
}