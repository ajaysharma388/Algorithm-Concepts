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
		ll *arr = new long long int[n+1]();
		for(ll i = 1; i <= n; ++i){
			string team;
			ll rank;
			cin >> team >> rank;
			arr[rank] ++;
		}
		ll badness = 0;
		ll pos = 1;
		for(ll i = 1; i <= n; ++i){
			while(arr[i]){
				badness += abs(pos-i);
				arr[i]--;
				pos++;
			}
		}
		cout << badness << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 7
// noobz 1
// llamas 2
// Winn3rz 2
// 5thwheel 1
// NotoricCoders 5
// StrangeCase 7
// WhoKnows 7
// 3
// ThreeHeadedMonkey 1
// MoscowSUx13 1
// NeedForSuccess 1

// Sample Output :

// 5
// 3