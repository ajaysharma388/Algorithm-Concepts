/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second


void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

int cellMitosis(int n, int x, int y, int z) {
	int *dp = new int[n+1];
	memset(dp,0,n+1);
	for(int i = 2; i <= n; ++i) {
		if(i&1) {
			int a = dp[(i-1)/2] + x + z;
			int b = dp[i-1] + y;
			dp[i] = min(a, b);
		} else {
			int a = dp[i/2] + x;
			int b = dp[i-1] + y;
			dp[i] = min(a, b);
		}
	}
	return dp[n];
}

int32_t main() {
	fastio(true);
	int testCases; cin >> testCases;
	while(testCases--) {
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		cout << cellMitosis(n, x, y, z) << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 7 1 2 2
// 12 2 1 3
// 18 4 2 1

// Sample Output :

// 6
// 6
// 15