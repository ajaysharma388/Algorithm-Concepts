#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void merge(int *a,int s,int e){
	int temp[100];
	int m=(s+e)/2,i=s,j=m+1,k=s;
	while(i<=m && j<=e){
		if(a[i]<a[j]) temp[k++]=a[i++];
		else temp[k++]=a[j++];
	}
	while(i<=m) temp[k++]=a[i++];
	while(j<=e) temp[k++]=a[j++];
	for(int i=s;i<=e;++i){
		a[i]=temp[i];
	}
	return;
}


void merge_sort(int a[],int s,int e){
	if(s>=e) return;
	int m=(s+e)/2;
	merge_sort(a,s,m);
	merge_sort(a,m+1,e);
	merge(a,s,e);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;++i) cin>>arr[i];
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;++i) cout<<arr[i]<<" ";
	return 0;
}