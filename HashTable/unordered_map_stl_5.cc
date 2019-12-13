// Question Find the itersection of two array's using hashing.
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
	vector<int> interArr;
	vector<int> unionArr;
	int m,n;
	cin >> m;
	for(int i=0;i<m;++i){
		int data;
		cin >> data;
		table.insert(make_pair(data,1));
	}
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		if(table.count(data)){
			table[data] = 2;
		}else{
			table.insert(make_pair(data,1));
		}	
	}
	for(auto node : table){
		if(node.second==2){
			interArr.push_back(node.first);
		}
		unionArr.push_back(node.first);
	}
	cout<<"Union : ";
	for(int i=0;i<unionArr.size();++i){
		cout<<unionArr[i]<<" ";
	}
	cout<<endl<<"Intersection : ";
	for(int i=0;i<interArr.size();++i){
		cout<<interArr[i]<<" ";
	}
	return 0;
}