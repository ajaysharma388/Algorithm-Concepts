#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

vector<int> vi;

void find_all_indexes(int *a,int i,int n,int key){
	if(i==n) return;
	if(a[i]==key) vi.push_back(i);
	find_all_indexes(a,i+1,n,key);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,key;
	cin >> n;
	int a[n] = {};
	for(int i=0;i<n;++i) cin>>a[i];
	cin >> key;
	find_all_indexes(a,0,n,key);
	for(int i=0;i<vi.size();++i) cout<<vi[i]<<" ";
	return 0;
}