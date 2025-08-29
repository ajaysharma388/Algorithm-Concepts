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
	ll a,b,c;
	cin >> a >> b >> c;
	ll res=1;
	for(int i=1;i<=b;++i){
		res*=a;
		res%=c;
	}
	cout<<res<<endl;
	return 0;
}