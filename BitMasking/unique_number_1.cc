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
	int n,count[64]={},temp;
	cin >> n;
	for(int i=0;i<n;++i){
		cin>>temp;
		int j=0;
		while(temp){
			if(temp&1)
				count[j]++;
			temp>>=1;
			j++;
		}
	}
	int ans=0;
	for(int i=0;i<64;++i){
		count[i]%=3;
		ans+=(count[i]*(1<<i));
	}
	cout<<ans<<endl;
	return 0;
}