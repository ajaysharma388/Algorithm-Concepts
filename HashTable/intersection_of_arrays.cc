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
	unordered_map<int,int> mp;
	vector<int> res;
	for(int i = 0; i < n; ++i){
		int data;
		cin >> data;
		if(mp.find(data) == mp.end()){
			mp[data] = 1;
			continue;
		}
		mp[data]++;
	}	
	for(int i = 0; i < n; ++i){
		int data;
		cin >> data;
		if(mp.find(data) != mp.end() and mp[data]){
			mp[data]--;
			res.push_back(data);
		}
	}
	sort(res.begin(), res.end());
	cout << "[";
	int i = 0;
	for(; i < res.size()-1; ++i){
		cout << res[i] << ", ";
	}
	cout << res[i] << "]" << endl;
	return 0;
}

// Sample Input :

// 7
// 1 2 3 1 2 4 1
// 2 1 3 1 5 2 2

// Sample Output :

// [1, 1, 2, 2, 3]