#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int partition(int *a,int s,int e){
	int i=s-1,j=s,p=a[e];
	for(;j<e;++j){
		if(a[j]<=p){
			swap(a[++i],a[j]);
		}
	}
	swap(a[++i],a[e]);
	return i;
}

void quick_sort(int *a,int s,int e){
	if(s>=e) return;
	int p=partition(a,s,e);
	quick_sort(a,s,p-1);
	quick_sort(a,p+1,e);
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
	quick_sort(a,0,n-1);
	for(int i=0;i<n;++i) cout<<a[i]<<" ";
	return 0;
}