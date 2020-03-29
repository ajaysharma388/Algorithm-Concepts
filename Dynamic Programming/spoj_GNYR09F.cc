#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[105][105][2];

// Solution is Based Out of Top Down DP.
// So, we have used recursion + memoisation.

int adjBitCount(int n,int k,int first) {
	if(n == 0) return 0;
	if(n == 1) {
		if(k == 0) return 1;
		else return 0;
	}
	// Checking if the state is not already computed.
	int &ans = dp[n][k][first];
	if(ans != -1) return ans;
	int result = -1;
	if(first & 1) {
		result = adjBitCount(n-1,k-1,1) + adjBitCount(n-1,k,0);
	} else {
		result = adjBitCount(n-1,k,1) + adjBitCount(n-1,k,0);
	}
	return ans = result;
}


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
	while(t--) {
		int no,n,k;
		cin >> no >> n >> k;
		memset(dp,-1,sizeof(dp));
		int ans = adjBitCount(n,k,1);
		ans += adjBitCount(n,k,0);
		cout << no << " " << ans << endl;
	}
	return 0;
}

// Sample Input :

// 10
// 1 5 2
// 2 20 8
// 3 30 17
// 4 40 24
// 5 50 37
// 6 60 52
// 7 70 59
// 8 80 73
// 9 90 84
// 10 100 90

// Sample Output :

// 1 6
// 2 63426
// 3 1861225
// 4 168212501
// 5 44874764
// 6 160916
// 7 22937308
// 8 99167
// 9 15476
// 10 23076518