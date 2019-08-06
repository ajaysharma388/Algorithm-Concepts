#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)


ull fastPower(ull a,ull b){
	return (b==1) 
		? a 
		: fastPower(a,b/2)*fastPower(a,(b-b/2));
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	ull a,b,c;
	r(a);r(b);
	c=fastPower(a,b);
	w(c);
	return 0; 
}