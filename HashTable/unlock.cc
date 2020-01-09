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
	ll n,k;
	cin >> n >> k;
	if(k >= n){
		for(ll i = n; i >= 1; --i){
			cout << i << " ";
		}
		return 0;
	}
	ll *number = new ll[n]();
	ll *idx = new ll[n+1]();
	for(ll i = 0; i < n; ++i) {
		cin >> number[i];
		idx[number[i]] = i; 
	}
	ll i = n;
	while(k) {
		ll best_idx = n - i;
		if(idx[i] == best_idx){
			i--;
			continue;
		}
		idx[number[best_idx]] = idx[i]; 
		swap(number[best_idx],number[idx[i]]);
		k--;	
		i--;
	}
	for(ll i = 0; i < n; ++i) {
		cout << number[i] << " ";
	}
	delete []number;
	delete []idx; 
	cout << endl;
	return 0;
}

// Sample Input : 

// 5 2
// 3 4 1 2 5

// Sample Output :

// 5 4 3 2 1