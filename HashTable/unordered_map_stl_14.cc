#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int largestSubArrayWithK(int *a,int n,int k){
	unordered_map<int,int> mp;
	int pre=0;
	int len=0;
	for(int i=0;i<n;++i){
		pre+=a[i];
		if(pre==k) len=i+1;
		if(mp.find(pre-k)!=mp.end()) len=max(len,i-mp[pre-k]);
		mp.insert(make_pair(pre,i));
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
		int n,k;
		cin >> n >> k;
		int *arr = new int[n];
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}
		cout<<largestSubArrayWithK(arr,n,k)<<endl;
	}	
	return 0;
}

// Sample Input :

// 2
// 7 8
// 1 -2 3 4 2 -2 1
// 7 5
// 1 -2 3 4 2 -2 1

// Sample Output :

// 5
// 7