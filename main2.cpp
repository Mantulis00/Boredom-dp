#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long counts[100010]; 


int main()
{//vars
    unsigned long long  n, k;
    unsigned long long maxim = 0;
    unsigned long long  ifMax = 0, lastMax = 0, currentMax = 0;

// input
    cin >> n;

    for (long int x=0; x<n; x++)
    {
         cin >> k;
        if (x==0) maxim = k;
        else if (maxim < k) maxim = k;
        counts[k] ++;
    }



// dp ( brute force )
	for (long int x=0; x<=maxim; x++)
	{
		// check -> if i picked last max 0 <- when i was on this i was in max 0 <-standing here 0 (0 0 0 )
		// if im standing on that one i cant pick it cuz it got deleted, so i check if its worth more to stand on alternative max and pick this one
		// or its worth more to move on with current maximum and dont pick this one
		currentMax = max(ifMax, lastMax + counts[x] *x ); 
		
		lastMax = ifMax;
		ifMax = currentMax;
	}

cout << currentMax;




    return 0;
}
