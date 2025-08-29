/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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

int arr[1000];
ll dp[1000][1000];

ll sum(int s, int e) {
	ll result = 0;
	for(int i = s; i <= e; i++){
		result += arr[i];
        result %= 100;
	}
	return result;
}

ll getMinSmoke(int i, int j) {
	// Base Case.
	if(i >= j) return 0;
	// if Already Evaluted.
	if(dp[i][j] != -1) return dp[i][j];
	// If not already calculated.
	dp[i][j] = INT_MAX;
	for(int k = i; k <= j; ++k) {
		dp[i][j] = min(dp[i][j], ((getMinSmoke(i, k) + getMinSmoke(k+1, j)) + sum(i, k)*sum(k+1, j)));
	}
	return dp[i][j];
}

ll getMinSmokeBU(int s, int e) {
	for(int i = s; i < e; ++i) {
		for(int j = s; j < e; ++j) {
			dp[i][j] = -1;
		}
	}

	for(int i = s; i < e; ++i) {
		for(int j = s; j < e; ++j) {
			if(i >= j) dp[i][j] = 0;
			else {
				dp[i][j] = INT_MAX;
				for(int k = i; k <= j; ++k) {
					dp[i][j] = min(dp[i][j],(dp[i][k]+dp[k+1][j]+sum(i,k)*sum(k+1,j)));
				}
			}
		}
	}
	return dp[s][e];
}

int main() {
	fastio(true);
	int n; 
	while((scanf("%d", &n))!=EOF) {
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		// Initialising the dp Array.
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j)
				dp[i][j] = -1;
		cout << "Top Down Dp : " << getMinSmoke(0, n-1) << endl;
		cout << "Bu Dp : " << getMinSmoke(0, n-1) << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 18 19
// 3 
// 60 40 20

// Sample Output :

// Top Down Dp : 342
// Bu Dp : 342
// Top Down Dp : 2400
// Bu Dp : 2400