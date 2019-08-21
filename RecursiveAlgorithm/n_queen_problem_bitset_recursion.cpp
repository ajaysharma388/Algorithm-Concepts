#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bitset<30> d1,d2,col;

void solve(int r,int n,int &ans){
	if(r==n){ 
		ans++; 
		return;
	}
	for(int c=0;c<n;++c){
		if(!d1[r-c+n-1] && !d2[r+c] && !col[c]){
			col[c]=d1[r-c+n-1]=d2[r+c]=1;
			solve(r+1,n,ans);
			col[c]=d1[r-c+n-1]=d2[r+c]=0;
		}
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,ans=0;
	cin >> n;
	solve(0,n,ans);
	cout<<ans<<endl;
	return 0;
}