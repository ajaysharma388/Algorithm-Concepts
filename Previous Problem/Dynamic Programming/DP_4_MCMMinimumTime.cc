/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
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

int getMinimumTimeForMCM(std::vector<int> &arr) {
	int dp[200][200];
	memset(dp, 0, sizeof (dp));
	int n = arr.size() -1;
	

	for(int i = 1; i < n; ++i) {
		int r = 0, c = i;
		while(c < n) {
			int val = INT_MAX;
			for(int p = r; p < c; ++p) {
				int x = dp[r][p] + dp[p+1][c] + arr[r]*arr[p+1]*arr[c+1];
				val = min(val, x);
			}
			dp[r][c] = val;
			r++; c++;
		}
	}
	return dp[0][n-1];
}

int32_t main() {
	fastio(true);
	int testCases; cin >> testCases;
	while(testCases--) {
		int n; cin >> n;
		vector<int> arr(n,0);
		for(int i = 0; i < n; ++i) 
			cin >> arr[i];
		cout << "Min Steps required to multiply set of Mat is " << getMinimumTimeForMCM(arr) << endl;
	}
	return 0;
}

// Sample Input :

// 1
// 5
// 4 2 3 1 3

// Sample Output :

// Min Steps required to multiply set of Mat is 26