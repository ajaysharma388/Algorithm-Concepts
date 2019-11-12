#include <iostream>   
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
	int a,b,m=0;
	r(a);r(b);
	for(int i=a;i<b;++i)
		for(int j=a+1;j<=b;++j)
			m=max(m,i^j);
	cout<<m<<endl;
	return 0;
}