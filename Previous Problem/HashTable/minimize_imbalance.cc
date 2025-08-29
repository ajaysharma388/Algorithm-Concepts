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
	int t;
	cin >> t;
	while(t--){
		int n,c;
		cin >> c >> n;
		int *arr = new int[2*c]();
		float ttl = 0;
		for(int i = 0; i < n; ++i){
			cin >> arr[i];
			ttl += arr[i];
		}
		float avg = (float) (ttl / c);
		float inb = 0.0f;
		sort(arr,arr+2*c);
		for(int i = 0; i < c; ++i){
			inb += abs(avg - (arr[i] + arr[2*c-i-1]));
		}
		printf("%0.5f\n", inb);
	}	
	return 0;
}

// Sample Input : 

// 3
// 2 3
// 6 3 8
// 3 5
// 51 19 27 14 33
// 5 9
// 1 2 3 5 7 11 13 17 19 

// Sample Output :

// 1.00000
// 6.00000
// 11.60000