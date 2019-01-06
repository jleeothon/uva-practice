#include <string.h>
#include <stdio.h>

int n;
char st[101];
int l; /* longitud total */
int k;
char *i, *j; // apuntadores al principio y final de cada grupo
int gl; /* longitud de grupo */
char t; /* variable temporal */

int main() {

    while(scanf("%d %s", &n, st) == 2) {
        l = strlen(st);
        gl = l / n;
        for (k = 0; k < n; k++) {
            i = st + gl * k;
            j = st + i + gl - 1;
            while (i < j) {
                *i ^= *j;
                *j ^= *i;
                *i ^= *j;
                i++, j--;
            }
        }
        printf("%s\n", st);
    }

    return 0;
}
