#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)


ull power(ull a,ull n){
	return (n==1)?a:(a*power(a,n-1));
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	ull a,b;
	r(a);r(b);
	w(power(a,b));
	return 0; 
}