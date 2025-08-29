#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[1005][1005];

// try to implement the recursive implementation.
int recursiveCode(string s,int i,int j) {
	// as the starting pt is i and cannot be lesser than j.
	if(j < i) return 0;
	// As the starting and ending points are same so length will be 1.
	if(i == j) return 1;
	if(s[i] == s[j]) {
		return 2 + recursiveCode(s,i+1,j-1);
	}
	int case1 = recursiveCode(s,i+1,j);
	int case2 = recursiveCode(s,i,j-1);
	return max(case1,case2);
}

int longestPalindromicSeq(string &s) {
	memset(dp,0,sizeof (dp));
	int n = s.length();
	// we are filling for all the strings with len 1.
	for(int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}
	// for len from 2 to n;
	for(int len = 2; len <= n; ++len) {
		for(int i = 0; i <= n-len; ++i) {
			int j = i+len-1;
			if(s[i] == s[j]) {
				dp[i][j] = dp[i+1][j-1] + 2;
			} else {
				dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
			}
		}
	}
	return dp[0][n-1];
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
		string s;
		cin >> s;
		cout << "Dp Solution : " << longestPalindromicSeq(s) << endl;
		cout << "Recursive : " << recursiveCode(s,0,s.length()) << endl;
	}	
	return 0;
}

// Sample Input :

// 2
// bbbab
// bccd

// Sample Output :

// Dp Solution : 4
// Recursive : 4
// Dp Solution : 2
// Recursive : 2