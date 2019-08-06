#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


int binarySearch(int *a,int s,int e,int k){
	int m=(s+e)/2;
	if(s>e) return -1;
	if(a[m]==k) return m;
	else if(a[m]>k) return binarySearch(a,s,m-1,k);
	else return binarySearch(a,m+1,e,k);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
	int item;
	cin>>item;
	cout<<binarySearch(a,0,n-1,item);
	return 0;
}