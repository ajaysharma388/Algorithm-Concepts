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
	map<int,int> mp;
	cin >> n;
	while(n--){
		int data;
		cin >> data;
		if(mp.find(data)==mp.end()){
			mp[data] = 1;
			continue;
		}
		mp[data]++;
	}
	pair<int,int> maximum;
	maximum = {INT_MIN,INT_MIN};
	for(auto node:mp){
		if(node.second > maximum.second){
			maximum = {node.first,node.second};
		}
	}
	cout << maximum.first <<endl;
	return 0;
}