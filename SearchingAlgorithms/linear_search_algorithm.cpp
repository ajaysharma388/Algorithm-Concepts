#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define r(n) scanf("%d",&n)
#define w(n) printf("%d ",n)
#define rep(i,n) for(int i=0;i<n;++i)
#define s string

int linear_search(int *a,int n,int key){
	rep(i,n) if(key==a[i]) return i;
	return -1;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	r(n);
	int arr[n];
	rep(i,n) r(arr[i]);
	int key;
	r(key);
	int index=linear_search(arr,n,key);
	if(index>0){
		cout<<"Element "<<key<<" found at "<<index<<" index."<<endl;
	}else{
		cout<<"Element not found in the array."<<endl;	
	} 
	return 0;
}

// time complexity of the linear search algorithm is O(n) in the worst case.
// and we can search the data in any list no matter's whether it
// is sorted or not.