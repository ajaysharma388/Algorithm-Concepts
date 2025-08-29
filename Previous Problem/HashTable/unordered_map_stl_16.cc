// Question : largest consecutive sub sequence in an array
// Time Complexity : O(maximum-minimum)
// Space Complexity : O(N) as it uses map to store the elemnts of array.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int longestConsecutiveSubSeq(int *arr,int n){
	map<int,int> mp;
	for(int i=0;i<n;++i){
		if(mp.find(arr[i])!=mp.end()) mp[arr[i]]++;
		else mp[arr[i]]=1;
	}
	auto it = mp.begin();
	int mn=it->first;
	it=mp.end();
	it--;
	int mx=it->first;
	int ans=0,count=0;
	for(int i=mn;i<=mx;++i){
		if(mp[i]){
			count++;
		}else{
			ans=max(ans,count);
			count=0;
		}
	}
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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}	
		cout<<longestConsecutiveSubSeq(arr,n)<<endl;
	}	
	return 0;
}

// Sample Input :

// 3
// 8
// 1 9 8 3 2 1 4 5
// 10
// 20 1 6 5 21 2 5 3 4 6
// 8
// 10 4 20 1 3 3 2 19

// Sample Input :

// 5
// 6 
// 4