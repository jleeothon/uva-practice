#include <stdio.h>


int max_sum ( int* arr, int lo, int hi ) {
	/*
	where:
		mls := max left sum
		mrs := max right sum
		lbs := left border sum
		rbs := right border sum
		mlbs := max left border sum
		mrbs := max right border sum
		mms := max middle sum
		ms := max sum
	*/
	int i;
	/* base case */
	if (lo == hi) return arr[lo];
	int mi, mls, mrs, lbs, rbs, mlbs, mrbs, mms, ms;
	mi = (lo+hi) / 2;
	/* calculate max left half sum and max right half sum */
	mls = max_sum(arr, lo, mi);
	mrs = max_sum(arr, mi+1, hi);
	/* calculate maximum sum that spans both halves */
	lbs = rbs = mlbs = mrbs = 0;
	for (i = mi; i >= lo; i--) {
		lbs += arr[i];
		if (lbs > mlbs) mlbs = lbs;
	}
	for (i = mi+1; i <= hi; i++) {
		rbs += arr[i];
		if (rbs > mrbs) mrbs = rbs;
	}
	/* calculate max middle sum */
	mms = mlbs + mrbs;
	/* check maximimum between mls, mms, mrs */
	ms = mls;
	if (mms > ms) ms = mms;
	if (mrs > ms) ms = mrs;
	return ms;
} // end max sum




int main() {
	int arr[] = {100, -8, -20, -25, 101, 1};
	printf("%d\n", max_sum(arr, 0, 5));
	return 0;
}