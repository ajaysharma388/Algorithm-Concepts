#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// This solution is based out of the recursive approach so the time complexity 
// of this solution is of the Order O(n^amount).
// where amount is the for what we are looking for the changes.
// n is the types of coins that we have had as the option. 

int minCoins(int coins[],int amount,int n) {
	// base Case.
	if(amount == 0) return 0;
	// Recursive case.
	int minCoin = INT_MAX;
	for(int i = 0; i < n; ++i) {
		if(amount-coins[i] >= 0){
			int ans = minCoins(coins,amount-coins[i],n);	
			minCoin = min(minCoin,ans+1);
		}
	}
	return minCoin;
}

// This Solution is based out of Bottom UP dynamic programming.
// The time complexity of this approach is O(N*Amt). And if the coins
// Options are contant you can say it is O(Amt).
// Space Complexity would be O(Amt).

int minCoinsDp(int coins[],int amount,int n) {
	int *dp = new int[amount+1];
	for(int i = 0; i <= amount; ++i) {
		dp[i] = INT_MAX;
	}	
	dp[0] = 0;
	for(int rupay = 1; rupay <= amount; ++rupay) {
		// we will itrate over all options.
		for(int i = 0; i < n; ++i) {
			if(coins[i] <= rupay) {
				int ans = dp[rupay-coins[i]];
				dp[rupay] = min(dp[rupay],ans+1);
			}
		}
	}
	return dp[amount];
}



int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
	int amount;
	cin >> amount;
	int n = sizeof (coins)/sizeof (int);
	// this call will take the huge time.
	cout << minCoins(coins,amount,n) << endl;
	cout << minCoinsDp(coins,amount,n) << endl;
	return 0;
}


// Sample Input :
// 39


// Sample Output :
// 5
// 5
// 3
// 3
