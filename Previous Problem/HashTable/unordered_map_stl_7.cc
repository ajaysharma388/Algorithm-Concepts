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
	unordered_map<int,int> table;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		if(table.count(data)==0){
			table[data] = 1; 
		}
	}	
	vector<int> arr;
	for(auto node:table){
		arr.push_back(node.first);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();++i){
		cout<<arr[i]<<" ";
	}
	return 0;
}

// Input :

// 10
// 1 2 1 1 1 3 2 7 7 5  

// Output : 

// 1 2 3 5 7