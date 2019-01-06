#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int id;
	float ratio;
} Job;

int compare_job(const void *a, const void *b) {
	const Job *ja = (const Job*) a;
	const Job *jb = (const Job*) b;
	float rdiff = ja->ratio - jb->ratio;
	return rdiff ? rdiff : ja->id - jb->id;
}

int main() {
	int t; // test cases
	int n; // jobs
	int i; //
	int days, fine;
	Job jobs[1000];
	Job *job_i; // job iterator

	// make readings
	scanf("%i", &t);
	while (t--) {
		scanf("%i", &n);
		job_i = jobs;
		i = 0;
		while (i < n) {
			scanf("%i %i", &days, &fine);
			job_i->id = i+1;
			job_i->ratio = fine/(float)days;
			job_i++;
			i++;
		}
	}
	
	// solve!
	qsort(jobs, n, sizeof(Job), compare_job);

	// print result
	printf("%i", (*jobs).id);
	for (i = 1; i < n; i++) {
		printf(" %i", jobs[i].id);
	}
	printf("\n");
	return 0;
}
