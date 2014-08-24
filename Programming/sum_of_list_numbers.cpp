#include <list>
using namespace std;


list<int> add_lists(list<int> l1, list<int> l2) { 
	l1.reverse();
	l2.reverse();
	list<int> result;
	int l1size = l1.size();
	int l2size = l2.size();
	if (l1size > l2size) {
		result.resize(l1size+1, 0);
		l2.resize(l1size, 0);
	} else {
		result.resize(l2size+1, 0);
		l1.resize(l2size, 0);
	}
	iterator i1 = l1.begin();
	iterator i2 = l2.begin();
	iterator 
	for (int i = 0; i < l1size; i++) {

	}
	return result;
}

int main() {
	return 0;
}