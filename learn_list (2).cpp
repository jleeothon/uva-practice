#include <list>

#include "Menu.h"

using namespace std;

int option;
list<int> l0;

void (*option_operations)(void)[3];

int main() {
	
	while ((option = menu(5, "-- choose: ",
		"add",
		"remove",
		"clear",
		"print",
		"exit")) - 5) {
		switch (option) {
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
		} // end switch
	} // end while
}