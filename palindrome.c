

int isPalindrome(char *s) {
	char *a, *b;
	a = b = s;
	while (*b) {
		b++;
	}
	while (a < b) {
		if (*a != *b) {
			return 0;
		}
		a++;
		b--;
	}
	return 1;
}

int isNumberPalindrome(int n) {
	int d[11] = {0};
	int *i, *j;
	i = j = d;
	while (n) {
		*i++ = n % 10;
		n /= 10;
	}
	while (j < i) {
		if (*j++ != *i--) {
			return 0;
		}
	}
	return 1;
}

