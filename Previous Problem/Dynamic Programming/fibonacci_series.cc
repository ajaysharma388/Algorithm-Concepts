#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"

// the recursive approach for finding the nth fibonacci number.
// Time Complexity Of this Approach is O(2^n).
// Space Complexity Of this Approach is O(n).

ll fib(ll n) {
	if(n == 0 || n == 1) {
		return n;
	}
	return fib(n-1) + fib(n-2);
}

// the recursive approach for finding the nth fibonacci number.
// Time Complexity Of this Approach is O(n).
// Space Complexity Of this Approach is O(n).

ll fibTopDown(ll n, ll *dp) {
	if(n == 0 || n == 1) {
		dp[n] = n;
		return dp[n];
	}
	// if not computed alredy.
	if(dp[n] != -1) return dp[n];
	dp[n] = fibTopDown(n-1,dp) + fibTopDown(n-2,dp);
	return dp[n];
}

// the recursive approach for finding the nth fibonacci number.
// Time Complexity Of this Approach is O(n).
// Space Complexity Of this Approach is O(n).

ll fibBottomUp(ll n) {
	ll *dp = new ll[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int curState = 2; curState <= n; ++curState) {
		dp[curState] = dp[curState-1] + dp[curState-2];
	}
	return dp[n];
}

// the recursive approach for finding the nth fibonacci number.
// Time Complexity Of this Approach is O(n).
// Space Complexity Of this Approach is O(1).

ll fibBDP(ll n) {
	ll a = 0;
	ll b = 1;
	ll c = 0;
	for(int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fib(5) << endl;
	ll *dp = new ll[6];
	for(int i = 0; i < 6; ++i) {
		dp[i] = -1;
	}
	cout << fibTopDown(5,dp) << endl;
	cout << fibBottomUp(5) << endl;
	cout << fibBDP(5) << endl;
	return 0;
}
