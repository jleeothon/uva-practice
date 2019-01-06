#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

typedef struct country{
	char n[100];
	int g,s,b;
} Country;

int compare( const void * pa, const void * pb){
	Country a = *((Country*)pb);
	Country b = *((Country*)pa);

	if( a.g != b.g )
		return a.g-b.g;
	if( a.s != b.s )
		return a.s-b.s;
	if( a.b != b.b )
		return a.b-b.b;

	return strcmp(b.n, a.n);
}

int main( int argc, char * argv[] ){
	Country countries[30];
	char in[200];
	char eoc;
	int i_country;
	int first_case = 0;
	do{
		if( first_case )
			printf("@\n");
		first_case = 1;
		i_country = 0;
		while( scanf("%[^\n]\n", in) != EOF && !(in[0] == '@' || in[0] == '#') )
		{
			sscanf(in, "%s %d %d %d", countries[i_country].n, &countries[i_country].g, &countries[i_country].s, &countries[i_country].b );
			i_country++;
		}
		eoc = in[0];

		qsort( countries, i_country, sizeof(Country), compare);

		for(int i=0; i<i_country; i++)
		{
			printf("%s\n", countries[i].n);
		}
	} while( eoc != '#' );
}
