#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll *cost = new ll[n]();
		ll *petrol = new ll[n]();
		for(int i = 0; i < n; ++i){
			cin >> cost[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> petrol[i];
		}
		ll min_cost = cost[0];
		ll ttl_cost = cost[0]*petrol[0];
		for(int i = 1; i < n; ++i){
			if(min_cost > cost[i]){
				min_cost = cost[i];
				ttl_cost += min_cost*petrol[i];
				continue;
			} else {
				ttl_cost += min_cost*petrol[i];
				continue;
			}
		}  
		cout << ttl_cost << endl;
	}	
	return 0;
}

// Sample Input :

// 1
// 2
// 5 1
// 1 2

// Sample Output :

// 7