#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define r(n) scanf("%d",&n)
#define w(n) printf("%d ",n)
#define rep(i,n) for(int i=0;i<n;++i)
#define s string

int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}

int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int a,b;
	cin >> a >> b;
	int m=max(a,b);
	a+=b;
	a-=m;
	cout << gcd(m,a) << endl;
	return 0;
}
