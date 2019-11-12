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
	int n;
	r(n);
	while(n--){
		int s,step=0;
		r(s);
		while(s>0){
			s=s&(s-1);
			step++;
		}
		// while(s>0){
		// 	if(s&1) step++;
		// 	s>>=1;
		// }
		cout<<step<<endl;
	}
	return 0;
}