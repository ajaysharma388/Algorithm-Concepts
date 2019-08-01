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
	for(int i=0;i<n;++i){
		int min=i;
		for(int j=i+1;j<n;++j){ 
			if(arr[j]<arr[min]){ 
				swap(arr[min],arr[j]);
			}
		}
	}
	rep(i,n) w(arr[i]);
	return 0;
}


// time complexity of this algorithm is O(n^2)
// in the worst case.