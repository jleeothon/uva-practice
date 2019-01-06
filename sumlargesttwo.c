int sumLargestTwo(int *a, int len) {
	if (len > 2) {
		int m, n, i, c;
		m = a[0];
		n = a[1];
		for (i = 0; i < len; i++) {
			c = a[i];
			if (c > n) {
				if (c > m) {
					n = m;
					m = c;
				} else {
					n = c;
				}
			}
		}
		return m + n;
	} else if (len = 1) {
		return a[0];
	} else {
		return 0;
	}
}
