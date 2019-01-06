#include <cstdio>
#include <cstdlib>
#include <cstring>

int suma_maxima( int arr[], int low, int high ){
	if( low == high )
		return arr[low];
	else{
		int mid, max_sum_izq, max_sum_der;
		mid = (low+high)/2;
		max_sum_izq = suma_maxima( arr, low, mid );
		max_sum_der = suma_maxima( arr, mid+1, high );

		int sum_izq_borde, sum_der_borde, max_sum_izq_borde, max_sum_der_borde;

		sum_izq_borde = 0;
		max_sum_izq_borde = arr[mid];
		sum_izq_borde = max_sum_izq_borde = 0;

		for( int i=mid; i >= low; i-- ){
			sum_izq_borde += arr[i];
			if( sum_izq_borde > max_sum_izq_borde ){
				max_sum_izq_borde = sum_izq_borde;
			}
		}

		sum_der_borde = 0;
		max_sum_der_borde = arr[mid+1];
		for( int i=mid+1; i<=high; i++){
			sum_der_borde += arr[i];
			if( sum_der_borde > max_sum_der_borde ){
				max_sum_der_borde = sum_der_borde;
			}
		}

		int max = max_sum_izq;
		if( max_sum_der > max ){
			max = max_sum_der;
		}

		if((max_sum_izq_borde + max_sum_der_borde) > max ){
			max = max_sum_izq_borde + max_sum_der_borde;
		}

		return max;
	}
}

int main(){
	int n_cases;
	int ncoins,i;
	char p1[30], p2[30];
	int coins[10050], maxp1, maxp2;
	scanf("%d\n", &n_cases);
	for( int i_case = 0; i_case < n_cases; i_case++ ){

		scanf("%d\n", &ncoins);
		scanf("%s", p1);
		for( i=0; i<ncoins; i++){
			scanf("%d", coins+i);
		}
		getchar();
		maxp1 = suma_maxima( coins, 0, ncoins-1);

		scanf("%s", p2);
		for( i=0; i<ncoins; i++){
			scanf("%d", coins+i);
		}
		getchar();
		maxp2 = suma_maxima( coins, 0, ncoins-1);

		if( maxp1 > maxp2 ){
			printf("%s %d\n", p1, maxp1);			
		} else if( maxp1 < maxp2 ){
			printf("%s %d\n", p2, maxp2);
		} else {
			printf("Tied %d\n", maxp1 );
		}

	}
}
