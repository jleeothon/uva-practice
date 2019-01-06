#include <cstdio>
#include <cstring>
#include <cstdlib>

void tolower( char * a ){
	int i=0;
	while( a[i] ){
		if( a[i] >= 'A' && a[i] <= 'Z' ){
			a[i] += 'a' - 'A';
		}
		i++;
	}
}

int main(){
	char read[50];
	char *a,*b, *c, *d;
	int min, hora, lenm, lenh;
	while( scanf("%[^\n]\n", read) != EOF ){
		a = strtok( read, " " );
		b = strtok( NULL, " " );
		c = strtok( a, ":" );
		d = strtok( NULL, ":");

		if( !a || !c || !d ){
			goto invalido;
		}

		hora = atoi(c);
		min = atoi(d);

		if( hora < 0 || hora >= 24 || min < 0 || min >= 60 ){
			goto invalido;
		}

		lenh = strlen(c);
		lenm = strlen(d);


		if( lenh <= 0 || lenh > 2 || lenm != 2 ){
			goto invalido;
		}

		if( b ){
			tolower(b);
			if( !strcmp(b,"am") || !strcmp(b,"pm") ){
				if( hora > 12 || hora <= 0 ){
					goto invalido;
				}
			} else if( strcmp( b, "hrs" ) )
				goto invalido;
		}


		printf("VALID\n");
		continue;
invalido:

		printf("INVALID\n");
		continue;
	}

	return 0;
}
