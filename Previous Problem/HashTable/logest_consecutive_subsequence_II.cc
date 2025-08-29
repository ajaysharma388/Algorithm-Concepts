#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

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
	int *arr = new int[n];	
	unordered_map<int,int> mp;
	for(int i=0; i<n; ++i){
		cin >> arr[i];
		// if current element is the part of two streaks
		// as left bound and the right bound.
		if(mp.find(arr[i]-1) != mp.end() and mp.find(arr[i]+1) != mp.end()){
			int l1 = mp[arr[i]-1];
			int l2 = mp[arr[i]+1];
			int lb = arr[i] - l1;
			int rb = arr[i] + l2;
			mp[lb] = l1 + l2 + 1;
			mp[rb] = l1 + l2 + 1;
			mp[arr[i]] = l1 + l2 + 1;
		}else if(mp.find(arr[i]-1) != mp.end()){
		// if current element is the part of streak
		// as left bound only.
			int l1 = mp[arr[i]-1];
			int lb = arr[i] - l1;
			mp[lb] = l1 + 1;
			mp[arr[i]] = l1 + 1;
		}else if(mp.find(arr[i]+1) != mp.end()){
		// if current element is the part of two streaks
		// as right bound only.
			int l2 = mp[arr[i]+1];
			int rb = arr[i] + l2;
			mp[rb] = l2 + 1;
			mp[arr[i]] = l2 + 1;
		}else{
		// if current element forms it's own streak. 
			mp[arr[i]] = 1;
		}
	}
	int maximum = INT_MIN;
	for(auto node:mp){
		maximum = max(maximum,node.second);
	}
	cout << maximum << endl;
	delete []arr;
	return 0;
}

// Sample Input :

// 12
// 5 1 9 2 6 3 7 8 10 12 13 14

// 12
// 5 1 9 2 6 3 7 8 10 12 13 4

// Sample Output :

// 6 

// 10