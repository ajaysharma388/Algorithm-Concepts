#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// time complexity will be O(N) and the 
// space complexity will also be O(N). 

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
	unordered_map<int,bool> mp;
	int maximum = INT_MIN;
	int minimum = INT_MAX;
	// Itrating over the elements each element and storing data into 
	// unordered_map and keping track of minimum and the maximum element
	// in the array.
	for(int i=0; i<n; ++i){
		cin >> arr[i];
		mp[arr[i]] = true;
		minimum = min(minimum,arr[i]);
		maximum = max(maximum,arr[i]);
	}
	int count = 0;
	int ans = 0;
	// Itrating between minimum and maximum to calculate the ans.
	for(int i=minimum; i<=maximum; ++i){
		if(mp.find(i) != mp.end()){
			// if element present the increase the count.
			count++;
		}else{
			// ans is updated 
			ans = max(ans,count);
			count = 0;
		}
	}
	ans = max(ans,count);
	cout << ans << endl;
	delete []arr;
	return 0;
}

// Sample Input :

// 12
// 5 1 9 2 6 3 7 8 10 12 13 14

// 12
// 5 1 9 2 6 3 7 8 10 12 13 4

// 12
// 5 1 9 2 6 3 7 8 10 12 13 11

// Sample Output :

// 6

// 10

// 9