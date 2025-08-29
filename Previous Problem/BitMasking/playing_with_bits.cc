#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define r(n) scanf("%d",&n)
#define w(n) printf("%d ",n)
#define rep(i,n) for(int i=0;i<n;++i)
#define s string

int findSetBits(int n){
	int j=0;
	while(n){
		n=(n&(n-1));
		j++;
	}
	return n;
}
int main(){
	// #ifndef ONLINE_JUGDE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// freopen("error.txt","w",stderr);
	// #endif	
	int s,e,n,ans=0;
	cin >> n;
	cout<<"Hello World!"<<endl;
	return 0;
}