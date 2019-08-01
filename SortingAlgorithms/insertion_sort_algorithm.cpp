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
	rep(i,n){
		int temp=arr[i];
		int j=i;
		while(j>0 && temp<arr[j-1]){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
	} 
	rep(i,n) w(arr[i]);
	return 0;
}

// time complexity of the this algorithm is O(n^2) in 
// the worst case.