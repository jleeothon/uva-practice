#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

void f(pair<string, int> p) {
	cout << p.first << ": "  << p.second << endl;
}

int main() {
	m["a"] = 8;
	m["b"] += 5;
	m["a"] += 1;
	for_each (m.begin(), m.end(), f);
	return 0;
}