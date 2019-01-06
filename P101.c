#include <stdio.h>

typedef unsigned short int number;

number n; /* between 1 and 25 */
number i, j;

char what[5]; // move or pile
char how[5]; // onto or over

number orig;
number dest;

typedef struct {
	number top; // zero-based; -1 for empty
	number blocks[25];
} stack;
stack stacks[25];

typedef struct 
	number stack;
	number position;
} where_block;
where_block where_blocks[25];

void moveonto();
void moveover();
void pileonto();
void pileover();

number which_function;
void (*function)(void)[4] = {
	moveonto, moveover, pileonto, pileover
};

int main() {
	scanf("%u\n", &n);
	for (i=0; i<n; i++) {
		stacks[i].top = where_blocks[i].position = 0;
		stacks[i].blocks[i] = where_blocks[i].stack = i;
	} // end for init stacks
	// now for the real part
	for (i=0; i<n; i++) {
		scanf("%s ", what); if (*what == 'q') goto quit;
		scanf("%u ", &orig);
		scanf("%s ", how);
		scanf("%u\n", &dest);
		if (orig==dest) continue; // invalid operation
		//where_orig = where_dest = -1;
		// where are orig and dest?
		/*for (i=0; i<n; i++) {
			for (j=0; j<=stacks[i].top; j++) {
				if (stacks[i].blocks[j] == orig) where_orig = i;
				if (stacks[i].blocks[j] == dest) where_dest = i;
				if (where_orig != -1 && where_dest != -1) break;
			} // end for j
		} // end for i*/	
		//if (where_orig == where_dest) continue; // invalid operation
		// find which function to execute
		//
		which_function = *what == 'm' ? 0 : 2; // move or pile
		if (how[1] == 'n') which_function++; // onto or over
		// execute!
		function[which_function]();
	}
	quit:
	; // todo
}

void moveonto() {

}

void moveover() {

}

void pileonto() {

}

void pileover() {

}

void unstack_orig(number od) { // 0 for orig, 1 for dest
	od = od ? orig : dest;
	for (i=stacks[where_blocks[]])
}