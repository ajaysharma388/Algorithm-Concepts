#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int linearSearch(int *a,int i,int n,int key){
	if(i==n) return -1;
	if(a[i]==key) return i;
	return linearSearch(a,i+1,n,key);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,item;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
	cin >> item;
	int i=linearSearch(a,0,n,item);
	if(i==-1){
		cout<<"Element Not Found!"<<endl;
	}else{
		cout<<"Element Found at "<<i<<" index."<<endl;
	}
	return 0;
}