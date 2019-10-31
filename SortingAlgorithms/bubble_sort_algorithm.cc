#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define r(n) scanf("%d",&n)
#define w(n) printf("%d ",n)
#define rep(i,n) for(int i=0;i<n;++i)
#define s string

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	r(n);
	int arr[n]={};
	rep(i,n) r(arr[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<n-i-1;++j) 
			if(arr[j]>arr[j+1]) 
				swap(arr[j],arr[j+1]);
	rep(i,n) w(arr[i]);
	return 0;
}


// time complexity of this algorithm is O(n^2)
// in the worst case.