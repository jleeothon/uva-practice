#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>

const double pi = acos(-1);

int main( int argc, char * argv[] ){

	double r1,r2,H,h,h0,k,r;
	while( scanf("%lf %lf %lf %lf", &r1, &r2, &H, &h ) != EOF && r1 && r2 && H && h )
	{
		if ( r1 != r2 ){
			h0 = H/((r2/r1)-1);
			k = r1/h0;
			r = pi * k * k / 3 * ( pow((h0 + H),3) - pow((h0 + h),3) );

		} else {
			r =	pi * r1 * r2 * (H-h);
		}
		printf("%.4lf\n", r );
	}

	return 0;
}
