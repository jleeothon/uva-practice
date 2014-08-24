// disjoint set

struct disjoint_sets {
	int *set;

	int get_set(int i) {
		if (i == set[i]) return i;
		else return set[i] = get_set(set[i]);
	}

	int join(int i, int j) {
		set[get_set(j)] = get_set(i);
	}

	int are_joined(int i, int j) {
		get_set(i) == get_set(j);
	}

};