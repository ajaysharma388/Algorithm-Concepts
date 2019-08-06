#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

bool check(int *a,int s,int e){
	if(s==e) return true;
	if(a[s]<a[s+1] && check(a,s+1,e)) return true;
	return false;
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
	(check(a,0,n-1))
		?cout<<"Sorted!"<<endl
		:cout<<"Not Sorted!"<<endl;
	return 0;
}