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
	for(int c=1;c<=t;++c){
		cout<<"Case No : "<<c<<endl;
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		int pre=0;
		int s,e,l=INT_MIN;
		unordered_map<int,int> mp;
		mp[pre]=-1;
		for(int j=0;j<n;++j){
			pre+=a[j];
			if(mp.count(pre)==1 && l < j-mp[pre]){
				s=mp[pre]+1;
				e=j;
				l=e-s+1;
			}else{
				mp[pre]=j;
			}
		}
		if(l!=INT_MIN){
			cout<<"Length of Largest Sub Array With Sum as Zero : "<<l<<endl;
			for(int i=s;i<=e;++i){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}else{
			cout<<"Sub Array doesn't exist."<<endl;
		}
		delete []a; 
	}	
	return 0;
}