// Frogger_oop.cpp

#include <stdio.h>

#define unsigned short int usi

class frog {
public:
	bool alive;
	usi row;
	usi col;
public:
	frog(usi col) {
		alive = true;
		row = 0;
		this->col = col;
	}
};

frog frogs[10];

class car {
public:
	usi row;
	usi col;
	usi speed;
public:
	car(usi row, usi col, usi speed) {
		this->row = row;
		this->col = col;
		this->speed = speed;
	}
	bool move() {
		col += speed;
	}
};

int main() {
	while (scanf("START") != EOF) {
		frog[]
	}
}