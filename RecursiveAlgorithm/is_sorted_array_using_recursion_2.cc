#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

bool isSorted(int *a,int n){
	if(n==1) return true;
	return (a[0]<a[1] && isSorted(a+1,n-1)) 
			? true : false;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
	(isSorted(a,n))
		?cout<<"Sorted!"<<endl
		:cout<<"Not Sorted!"<<endl;
	return 0;
}