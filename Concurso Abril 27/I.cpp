#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>

using namespace std;

typedef struct{
	int day,value;
} Event;

bool operator<(const Event &a, const Event &b ){
	return a.day>b.day;
}

int main(int argc, char const *argv[])
{
	priority_queue<Event> queue;
	int ncases,nmails,maxcap,imail,iarrival,ideletion,iweight, currentcap, cap90,over,maxusedcap,cap90_floor;
	Event e;
	scanf("%d", &ncases);
	while( ncases-- ){
		scanf("%d %d", &nmails, &maxcap);
		cap90_floor = (int)floor(maxcap * 0.9);
		cap90 = (int)ceil(maxcap * 0.9);
		maxusedcap = 0;
		for(imail=0;imail<nmails;imail++){
			scanf("%d %d %d", &iarrival, &ideletion, &iweight);

			e.day = iarrival;
			e.value = iweight;

			queue.push(e);

			e.day = ideletion;
			e.value = (-1 * iweight);

			queue.push(e);
		}

		currentcap = 0;

		while( !queue.empty() ){
			e = queue.top();
			queue.pop();

			currentcap += e.value;

			if( maxusedcap < currentcap )
				maxusedcap = currentcap;
		}

		while( !queue.empty() )
			queue.pop();

		if( maxusedcap > maxcap ){
			over = maxusedcap - maxcap;
			printf("BLOCKED %d\n", over);
		} else if( maxusedcap > cap90_floor ){
			over = (int)ceil((((double)(maxusedcap)) - ( 0.9 * maxcap ) ) / 0.9 );

			printf("OVERLOAD %d\n", over );
		} else {
			printf("OK\n");
		}


	}
	return 0;
}