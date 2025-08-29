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
	ll n,num=0,a=0;
	r(n);
	ll A[n]={};
	rep(i,n) r(A[i]);
	rep(i,n) num^=A[i];
	ll temp=num;
	ll i=0;
	while(temp){
		if(temp&1) break;
		temp>>=1;
		i++;
	}
	ll mask=(1<<i);
	rep(i,n) if(A[i]&mask) a^=A[i];
	cout<<(a^num)<<" "<<a; 
	return 0;
}