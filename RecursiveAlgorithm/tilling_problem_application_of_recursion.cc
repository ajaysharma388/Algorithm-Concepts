#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

ll probable_arr(ll n,ll m,ll o){
	if((m==1 && n==o) || (m==o &&n==1)) return 1;
	if(n==m) return 2;
	ll p=0;
	if(n>=o) p+=probable_arr(n,m-1,o);
	p+=probable_arr(n-1,m,o);
	return p;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<probable_arr(n,m,m)<<endl;
	}
	return 0;
}