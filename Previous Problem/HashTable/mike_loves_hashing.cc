#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

map<int,int> mp;

bool compare(int a,int b){
	return mp[a] < mp[b];
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> res;
	int n;
	cin >> n;
	int*arr = new int[n]();
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		if(mp.find(arr[i]) == mp.end()){
			mp[arr[i]] = i;
			res.push_back(arr[i]);
		} else {
			mp[arr[i]] = i;
		}
	}	
	sort(res.begin(), res.end(), compare);
	for(int i = 0; i < res.size(); ++i){
		cout << res[i] << endl;
	}
	delete []arr;
	return 0;
}