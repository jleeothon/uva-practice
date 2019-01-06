#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>

#define MAX(a,b) (a)>=(b)?(a):(b)

int main(){
	int ncase;
	scanf("%d", &ncase);
	int c,n,i,j,k,a,b;
	int mat[1200][300];
	int pi[300],bi[300];
	while(ncase--){
		scanf("%d %d", &n, &c);
		for( i=0; i<n; i++){
			scanf("%d %d",pi+i, bi+i);
		}

		for( i=0; i<n; i++ ){
			mat[0][i] = 0;
		}


		for( i=0; i<=c; i++ ){
			for( j=0; j<n; j++ ){
				a = mat[i][j-1];
				k = i-pi[j];
				if( k >= 0 ){
					b = mat[k][j-1]+bi[j];
					mat[i][j] = MAX(a,b);
				} else {
					mat[i][j] = a;
				}
			}
		}

		printf("%d\n", mat[c][n-1]);
	}
	return 0;
}
