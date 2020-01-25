#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

const int n = 4;

int grid[10][10] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int visited_all = (1<<n)-1;

int tsp(int mask,int pos) {
	// if all the cities have already visited.
	if(mask == visited_all) {
		return grid[pos][0];
	}
	int ans = INT_MAX;
	// try to visit all the cities.
	for(int city = 0; city < n; ++city) {
		int flag = mask & (1<<city);
		if(flag == 0) {
			int distance = grid[pos][city] + tsp(mask | (1<<city),city); 
			ans = min(ans,distance);
		}
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << tsp(1,0) << endl;
	return 0;
}

// Sample Output :

// 85