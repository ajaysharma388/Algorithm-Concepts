// Question : Largest sub array with sum as zero.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int largestSubArrayWithZeroSum(int *a,int n){
	unordered_map<int,int> mp;
	int pre=0;
	int len=0;
	for(int i=0;i<n;++i){
		pre+=a[i];
		if(a[i]==0 and len==0) len=1;
		if(pre==0) len = max(len,i+1);
		if(mp.find(pre)!=mp.end()) len=max(len,i-mp[pre]);
		else mp[pre]=i;
	}
	return len;
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
	while(t--){
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}
		cout<<largestSubArrayWithZeroSum(arr,n)<<endl;
	}	
	return 0;
}

// Sample Input : 

// 2
// 7
// 1 -2 -3 4 2 -2 -1
// 7
// 1 -2 3 4 2 -2 1

// Sample Output :

// 6
// 2