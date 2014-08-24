// is bigger smarter?

struct elephant {
	int n;
	int weight;
	int iq;
	int compQsort (void* a, void* b) {
		elephant *ea = (elephant*) a;
		elephant *eb = (elephant*) b;
		int wd = ea->weight - eb->weight;
		return wd ? wd : (ea->iq - eb->iq);
	}
	int compLIs (elephant* a, elephant* b) {
		return (a->weight < b->weight and a->iq > b->iq) ?
			-1 : 0;
	}
};

// Returns the length of the longest increasing subsequence.
// Note that this is looking for the longest strictly increasing subsequence.  
//    This can be easily modified for other situations.



int LIS(int* a, int N ) {
   int *best, *prev, i, j, max = 0;
   best = (int*) malloc ( sizeof( int ) * N );
   prev = (int*) malloc ( sizeof( int ) * N );
 
   for ( i = 0; i < N; i++ ) best[i] = 1, prev[i] = i;
 
   for ( i = 1; i < N; i++ )
      for ( j = 0; j < i; j++ )
         if ( a[i] > a[j] && best[i] < best[j] + 1 )
            best[i] = best[j] + 1, prev[i] = j;  // prev[] is for backtracking the subsequence
 
   for ( i = 0; i < N; i++ )
      if ( max < best[i] )
         max = best[i];
 
   free( best );
   free( prev );
 
   return max;
}