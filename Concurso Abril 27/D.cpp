#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

int main( int argc, char * argv[] ){

	int ncase, a,b,c,d;
	scanf("%d", &ncase);
	while( ncase-- ){
		scanf("%d %d", &a, &b);

		c = ((a+1)*(a+2))/2;
		d = ((a+1)/2) - 1;

		if( a%2==1 && (c-d) >= b )
		{
			printf("Yes\n");
			continue;
		} 

		if( a%2==0 && c >= b )
		{
			printf("Yes\n");
			continue;
		} 

		printf("No\n");
	}

	return 0;
}
