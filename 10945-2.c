/*
 * 10945 Mother Bear
 * http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1886
 * Johnny Lee
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ispal(char* s) {
    char *a, *b;
    a = s;
    b = s + strlen(s) - 1;
    while (a < b) {
        if (!isalpha(*a)) {
            a++;
            continue;
        }
        if (!isalpha(*b)) {
            b--;
            continue;
        }
        if (tolower(*a) != tolower(*b)) {
            return 0;
        }
        a++;
        b--;
    }
    return 1;
}

int main() {
    char s[1000] = {0};
    while (scanf("%[^\n]\n", s), strcmp(s, "DONE")) {
        if (ispal(s)) {
            puts("You won't be eaten!");
        } else {
            puts("Uh oh..");
        }
    }
    return 0;
}
