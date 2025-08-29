#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// this is purly recursive solution to the problem
// time complexity is O(3^N).
// space complexity is O(N).

int ways(int n) {
	if(n == 0) return 1;
	if(n < 0) return 0;
	int ans = ways(n-1) + ways(n-2) + ways(n-3);
	return ans; 
}

// this is purly recursive solution to the problem
// time complexity is O(3^N).
// space complexity is O(N).

void getAllPossibleWays(int n,int &res,int curPos = 0) {
	if(curPos > n) return;
 	if(curPos == n) {
		res++;
		return;
	}
	// recursive call.
	for(int step = 1; step <= 3; ++step) {
		getAllPossibleWays(n,res,curPos+step);
	}
	return;
}

// this is purly iterative solution to the problem
// or we can say this bottom up DP
// time complexity is O(N).
// space complexity is O(N).

int bottomUp(int n) {
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[n];
}

// this is purly iterative solution to the problem
// or we can say this bottom up DP
// time complexity is O(NK).
// space complexity is O(N).

int bottomUpDP1(int n,int k) {
	int *dp = new int[n+1];
	dp[0] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i] = 0;
		for(int step = 1; step <= k; ++step){
			dp[i] += ((i-step) >= 0) ? dp[i-step] : 0;
		}
	}
	return dp[n];
}

// not sure about when i-k < 0 what to do.

int bottomUpDP2(int n,int k) {
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; ++i) {
		if(i-k >= 0) {
			dp[i] = 2*dp[i-1] - dp[i-k]; 
		} 
	}	
}

// Top Down DP Approach.
// this solution uses recursion + memoisation to solve the problem
// time complexity is O(N).
// space complexity is O(N).

int topDownApproach(int n,int *dp) {
	if(n == 1 or n == 2) return dp[n] = n;
	if(n == 3) return dp[n] = 4;
	if(dp[n] != -1) return dp[n];
	dp[n] = topDownApproach(n-1,dp)+topDownApproach(n-2,dp)+topDownApproach(n-3,dp);
	return dp[n];
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,res = 0;
	cin >> n;
	int *dp = new int[n+1];
	for(int i = 0; i <= n; ++i) dp[i] = -1;
	cout << topDownApproach(n,dp) << endl;
	getAllPossibleWays(n,res);
	cout << res << endl;
	cout << ways(n) << endl;	
	cout << bottomUp(n) << endl;
	cout << bottomUpDP1(5,3) << endl;
	cout << bottomUpDP2(5,4) << endl;	
	return 0;
}