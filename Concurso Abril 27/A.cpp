#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>

int comp( const void * a, const void * b ){
	return (*(char*)a)-(*(char*)b);
}
int main(){

	char in[20],sorted[20], respuesta[20];
	int ncase, icase, i,len, val[20];
	int first = 0;
	while( scanf("%s", in) != EOF ){
		strcpy(sorted, in );
		len = strlen(sorted);
		qsort( sorted, strlen(sorted), 1, comp);

		printf("\n");

		scanf("%d\n\n", &ncase);

		for( icase=0; icase<ncase; icase++ ){
			for(i=0; i<len; i++ ){
				scanf("%d", val+i);
				respuesta[val[i]-1] = sorted[i];
			}
			respuesta[len]=0;

			printf("%s\n", respuesta);

		}

		getchar();
	}

	return 0;
}
