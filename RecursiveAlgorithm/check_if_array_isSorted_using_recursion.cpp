#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isSorted(ll *a,int i,int n){
	if(i==n-1){
		return true;
	}
	return (a[i]<=a[i+1])? isSorted(a,i+1,n): false; 
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	ll arr[n] = {};
	for(int i=0;i<n;++i) cin>>arr[i];
	(isSorted(arr,0,n))?cout<<"true\n":cout<<"false\n";
	return 0;
}