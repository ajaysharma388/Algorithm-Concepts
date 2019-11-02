#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

int mul(int a,int b){
	if(b==1) return a;
	if(b==-1) return -1*a;
	return mul(a,b/2)+mul(a,b-b/2);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int a,b;
	cin>>a>>b;
	cout<<mul(a,b)<<endl;
	return 0;
}