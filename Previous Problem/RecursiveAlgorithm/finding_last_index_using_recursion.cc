#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int findIndex(ll *a,ll i,ll n,ll key){
	if(i==n) return -1;
	ll index = findIndex(a,i+1,n,key);
	return (a[i]==key)
		?max(i,index)
		:index;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ll n,key;
	cin >> n;
	ll arr[n]={};
	for(ll i=0;i<n;++i) cin>>arr[i];
	cin>>key;
	cout<<findIndex(arr,0,n,key);
	return 0;
}