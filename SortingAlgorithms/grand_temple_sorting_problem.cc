#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	int vx[n],vy[n];
	for(int i=0;i<n;++i){
		cin>>vx[i]>>vy[i];
	}
	sort(vx,vx+n);
	sort(vy,vy+n);
	int dx=0,dy=0;
	for(int i=1;i<n;++i){
		dx=max(dx,vx[i]-vx[i-1]);
		dy=max(dy,vy[i]-vy[i-1]);
	}
	cout<<(dx-1)*(dy-1)<<endl;
	return 0;
}