#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int recSearchInRotatedArray(int *a,int s,int e,int k){
	int m=(s+e)/2;
	if(a[m]==k) return m;
	if(a[s]<a[m]){
		return(a[s]<=k && k<a[m]) 
			?recSearchInRotatedArray(a,s,m-1,k)
			:recSearchInRotatedArray(a,m+1,e,k);
	}
	return (a[m]<k && k<=a[e])
		?recSearchInRotatedArray(a,m+1,e,k)
		:recSearchInRotatedArray(a,s,m-1,k);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,key,k;
	cin >> n;
	int a[n] = {};
	for(int i=0;i<n;++i) cin >> a[i];
	cin >> key;
	cout << recSearchInRotatedArray(a,0,n-1,k);
	return 0;
}