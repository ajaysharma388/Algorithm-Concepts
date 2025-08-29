// Question : Finding the Length of the largest sub array having 
// Sum as zero.
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
		unordered_map<int,vector<int>> mp;
		int pre = 0;
		int s,e,l = INT_MIN;
		mp[pre].push_back(-1);
		for(int i=0;i<n;++i){
			pre+=a[i];
			if(mp.count(pre)==1){
				for(int j=0;j<mp[pre].size();++j){
					if(l<i-mp[pre][j]+1){
						s=mp[pre][j]+1;
						e=i;
						l=e-s+1;
					}
				}
			}
			mp[pre].push_back(i);
		}
		if(l!=INT_MIN){
			cout<<"Length Of The Largest SubArray : "<<l<<endl;
			for(int i=s;i<=e;++i){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}else{
			cout<<"SubArray Doesn't exist."<<endl;
		}
		delete []a;
	}
	return 0;
}

// Sample Output :

// 2
// 6
// 6 -1 2 -7 1 -1
// 7
// 4 3 -4 1 2 1 -3

// Sample Input :

// Case No : 1
// Length Of The Largest SubArray : 6
// 6 -1 2 -7 1 -1 
// Case No : 2
// Length Of The Largest SubArray : 6
// 3 -4 1 2 1 -3 