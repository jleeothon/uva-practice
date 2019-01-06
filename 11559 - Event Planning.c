/*

Event Planning
11559

As you didn't show up to the yearly general meeting of the Nordic Club of Pin
Collectors, you were unanimously elected to organize this years excursion to Pin
City. You are free to choose from a number of weekends this autumn, and have to
find a suitable hotel to stay at, preferably as cheap as possible. 

 You have some constraints: The total cost of the trip must be within budget, of
 course. All participants must stay at the same hotel, to avoid last years
 catastrophe, where some members got lost in the city, never being seen again. 

 Input  
 The input file contains several test cases, each of them as described below. 

 The first line of input consists of four integers: 1  N  200 , the number of
 participants, 1  B  500000 , the budget, 1  H  18 , the number of hotels to
 consider, and 1  W  13 , the number of weeks you can choose between. Then
 follow two lines for each of the H  hotels. The first gives 1  p  10000 , the
 price for one person staying the weekend at the hotel. The second contains W
 integers, 0  a  1000 , giving the number of available beds for each weekend
 at the hotel. 

 Output  

 For each test case, write to the output the minimum cost of the stay for your
 group, or ``stay home'' if nothing can be found within the budget, on a line by
 itself. 

 Sample Input  
3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13

 Sample Output  

900
stay home

*/

#include <stdio.h>

/* participants, budget, number of hotels, weeks */
int N, B, H, W;
/* price per person */
int p;
/* beds each week */
int b;

long int cost_for_group[18];

int i, j;

int this_hotel_may_be;
int this_hotel_cost;
int least_cost_yet;

const int max_cost_possible = 26000000; /* 200 * 13 * 1000 */
const int max_hotels = 18;
const int max_budget = 500000;

int main() {
	while (scanf("%d %d %d %d\n", &N, &B, &H, &W) != EOF) {
		least_cost_yet = 0;
		while (H--) {
			this_hotel_cost = 0;
			scanf("%d", &p);
			while (W--) {
				scanf("%d", &b);
				if (b >= N) {
					this_hotel_cost = N * p;
					break;
				}
			} /* end while W */
			while (W--); /* consume rest of weeks */
			if (this_hotel_cost < least_cost_yet || !least_cost_yet) {
				least_cost_yet = this_hotel_cost;
			}
		} /* end while H */
		if (least_cost_yet <= B) {
			printf("%d\n", least_cost_yet);
		} else {
			puts("stay home");
		}
	} /* end while ! EOF */
}