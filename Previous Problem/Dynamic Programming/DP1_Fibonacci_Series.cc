/******************************************
* AUTHOR : AJAY SHARMA                    *
* NICK : ajaysharma388                    *
******************************************/
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


int calculate_nth_fib(int n) {
	if(n < 0) return -1;
	if(n == 0 or n == 1) return n;
	// Recursive Case.
	int nth = calculate_nth_fib(n-1)+calculate_nth_fib(n-2);
	return nth;
}

int calculate_nth_fib_TD(int n,int *dp) {
	if(n < 0) return -1;
	if(n == 0 or n == 1) return n;
	// If already evaluted.
	if(dp[n] != -1) return dp[n];
	// else Recursive Case.
	int nth = calculate_nth_fib_TD(n-1,dp)+calculate_nth_fib_TD(n-2,dp);
	return dp[n] = nth;
}

int calculate_nth_fib_BU(int n,int *dp) {
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int32_t main() {
	fastio(true);
	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n;
		cin >> n;
		int *dp = new int[n+1];
		for(int i = 0; i <= n; ++i) dp[i] = -1;
		cout << n << "th fibonacci Series " << calculate_nth_fib_TD(n,dp) << endl;
		cout << n << "th fibonacci Series TD " << calculate_nth_fib_TD(n,dp) << endl;
		cout << n << "th fibonacci Series BU " << calculate_nth_fib_BU(n,dp) << endl;
	}
	return 0;
}

// Sample Input : 

// 1 
// 8

// Sample Output : 

// 8th fibonacci Series 21
// 8th fibonacci Series TD 21
// 8th fibonacci Series BU 21