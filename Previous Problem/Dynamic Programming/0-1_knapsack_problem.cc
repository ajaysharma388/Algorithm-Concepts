#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"



int knapsack(int wts[],int price[],int N,int W) {
	// Base Case For this problem. 
	if(N == 0 or W == 0) return 0;
	int inc = 0;
	// Inclusion Of the current State.
	if(wts[N-1] <= W) {
		inc = price[N-1] + knapsack(wts,price,N-1,W - wts[N-1]);
	}
	int exc = 0;
	// Excluding the current state.
	exc = 0 + knapsack(wts,price,N-1,W);
	// now we have profit for including the current state and 
	// excluding the current state as well then we just need 
	// to return the maximum among these two.
	return max(inc,exc);
}

// Time Complexity Of this Solution Is Of the Order O(N*W).
// Space Complexity is also O(N*W).

int bottomUp(int wts[],int price[],int N,int W) {
	int dp[100][100] = {0};
	// considering a range of wts from i-N.
	for(int i = 0; i <= N; ++i) {
		// checking for capacity b/w 0-W
		for(int w = 0; w <= W; ++w) {
			if(i == 0 or w == 0) dp[i][w] = 0;
			else {
				int inc = 0; int exc = 0;
				// inclusion.
				if(wts[i-1] <= w) {
					inc = price[i-1] + dp[i-1][w-wts[i-1]];
				}
				// exclusion.
				exc = dp[i-1][w];
				dp[i][w] = max(inc,exc);
			}
		}
	}
	return dp[N][W];
}

// Solution For the Same But for Unbounded Knapsack Problem.

int unBoundedKnapsack(int wts[],int price[],int N,int W) {
	// Base Case For this problem. 
	if(N == 0 or W == 0) return 0;
	int inc = 0;
	// Inclusion Of the current State.
	if(wts[N-1] <= W) {
		inc = price[N-1] + unBoundedKnapsack(wts,price,N,W - wts[N-1]);
	}
	int exc = 0;
	// Excluding the current state.
	exc = 0 + unBoundedKnapsack(wts,price,N-1,W);
	// now we have profit for including the current state and 
	// excluding the current state as well then we just need 
	// to return the maximum among these two.
	return max(inc,exc);
}

// Time Complexity Of this Solution Is Of the Order O(N*W).
// Space Complexity is also O(N*W).

int UnBoundedKanpsackBUP(int wts[],int price[],int N,int W) {
	int dp[100][100] = {0};
	// considering a range of wts from i-N.
	for(int i = 0; i <= N; ++i) {
		// checking for capacity b/w 0-W
		for(int w = 0; w <= W; ++w) {
			if(i == 0 or w == 0) dp[i][w] = 0;
			else {
				int inc = 0; int exc = 0;
				// inclusion.
				if(wts[i-1] <= w) {
					inc = price[i-1] + dp[i][w-wts[i-1]];
				}
				// exclusion.
				exc = dp[i-1][w];
				dp[i][w] = max(inc,exc);
			}
		}
	}
	return dp[N][W];
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int wts[] = {2, 2, 3, 1};
	int price[] = {5, 20, 100, 30};
	int W = 5;
	int N = 4;
	int result = knapsack(wts,price,N,W);
	cout << result << endl;	
	result = bottomUp(wts,price,N,W);
	cout << result << endl;	
	result = unBoundedKnapsack(wts,price,N,W);
	cout << result << endl;	
	result = UnBoundedKanpsackBUP(wts,price,N,W);
	cout << result << endl;	
	return 0;
}

// Sample Output :

// 130
// 130
// 160
// 160