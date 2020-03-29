#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// Time Complexity of this Solution is O(N)
// Space Complexity is O(n).
// can we do better than this ?
int numberOfArithmaticSlices(vector<int> &A) {
	int n = A.size();
	int result = 0;
	int *dp = new int[n]();
	for(int i = 2; i < n; ++i) {
		if((A[i] - A[i-1]) == (A[i-1] - A[i-2])) 
			dp[i] = 1 + dp[i-1];
		else
			dp[i] = 0;
		result += dp[i];
	}
	return result;
}

// Time Complexity of this Solution is O(N)
// Space Complexity is O(1).
// can we do better than this ?
int numberOfArithmaticSlices_Op(vector<int> &A) {
	int n = A.size();
	int result = 0;
	int dp = 0;
	for(int i = 2; i < n; ++i) {
		if((A[i] - A[i-1]) == (A[i-1] - A[i-2])){
			dp++;
			result += dp;
		} else {
			dp = 0;
		}
	}
	return result;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> A(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	cout << numberOfArithmaticSlices(A) << endl;
	cout << numberOfArithmaticSlices_Op(A) << endl;
	return 0;
}

// Sample Input :

// 4
// 1 2 3 4
// 10
// -3 4 8 10 12 22 26 28 30 31

// Sample Output :

// 3
// 2