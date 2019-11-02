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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		for(int i=0;i<n;++i){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		delete []a;
	}	
	return 0;
}