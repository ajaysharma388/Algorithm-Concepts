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
	int *arr = new int[n]();
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}	
	int i = 0;
	int j = 0;
	int count = 0;
	unordered_map<int,bool> mp;
	for(;i < n; ++i){
		while(mp.find(arr[j]) == mp.end() and j < n){
			mp[arr[j]]=true;
			count += ((j-i+1)*(j-i+2))/2;
			j++;
		}
		mp.erase(arr[i]);
	}
	cout << count << endl;
	return 0;
}

// Sample Input :

// 3
// 1 2 3

// 5
// 1 2 3 2 4

// Sample Output :

// 10
// 19