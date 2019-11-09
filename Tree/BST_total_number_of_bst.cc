#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

ll dp[100] = {0};

ll catalan(ll n){
	if(n==0){
		return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=catalan(i-1)*catalan(n-i);
	}
	dp[n] = ans;
	return ans;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,possible=0;
	cin >> n;
	for(int i=0;i<=n;++i){
		cout<<catalan(i)<<" ";
	}
	cout<<endl;
	return 0;
}