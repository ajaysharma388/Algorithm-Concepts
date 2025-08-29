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

int Factorial(int n) {
	// Base Case.
	if(n == 0 or n == 1) return 1;
	return n*Factorial(n-1);
}


int Factorial_TD(int n,int *dp) {
	// Base Case.
	if(n == 0 or n == 1) return 1;
	// if already evaluated.
	if(dp[n] != -1) return dp[n];
	// else
	return dp[n] = n*Factorial_TD(n-1,dp);
}

int Factorial_BU(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}


int32_t main() {
	fastio(true);
	int testCases;
	cin >> testCases;
	while(testCases--) {
		int n;
		cin >> n;
		int *dp = new int[n+1];
		for(int i = 0; i <= n; ++i) dp[i] = -1;
		cout << "Factorial of " << n << " is " << Factorial(n) << endl;
		cout << "Factorial of " << n << " is using TD " << Factorial_TD(n,dp) << endl;
		cout << "Factorial of " << n << " is using BU " << Factorial_BU(n) << endl;
	} 
	return 0;
}