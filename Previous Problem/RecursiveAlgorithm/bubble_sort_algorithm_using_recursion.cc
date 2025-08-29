#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void bubble_sort(int a[],int n){
	if(n==1) return;
	for(int i=0;i<n-1;++i){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	bubble_sort(a,n-1);
}

// now we are trying to remove the loop as well 
// since it is a recursive implementation.

void recursive_bubble_sort(int a[],int i,int n){
	if(n==1) return;
	if(i==n-1) return recursive_bubble_sort(a,0,n-1);
	if(a[i]>a[i+1]) swap(a[i],a[i+1]);
	recursive_bubble_sort(a,i+1,n);
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
	for(int i=0;i<n;++i) cin >> a[i];
	recursive_bubble_sort(a,0,n);
	for(int i=0;i<n;++i) cout << a[i] <<" ";
	return 0;
}