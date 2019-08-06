#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)


void fibonacci(ull a,ull b,ull term){
	if(term==0) return;
	ull c=a+b;
	cout<<c<<" ";
	fibonacci(b,c,term-1);
}

int fib(int n){
	return (n==0 || n==1)?n:fib(n-1)+fib(n-2);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ull a,b,c;
	r(a);r(b);r(c);
	fibonacci(a,b,c);
	return 0;
}