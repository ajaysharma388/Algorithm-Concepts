#include <iostream>   
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
	int n,m=0;
	r(n);
	int arr[n]={};
	rep(i,n){
		r(arr[i]);
		m=max(m,arr[i]);
	}
	int count[m]={};
	rep(i,n){
		count[arr[i]-1]++;
	}
	rep(i,m){ 
		while(count[i]>0){
			cout<<i+1<<" ";
			count[i]--;
		}
	}
	return 0;
}

// time complexity of the sorting O(n+max)
// where, max is the highest element in the array.
// and n be the size of the array.