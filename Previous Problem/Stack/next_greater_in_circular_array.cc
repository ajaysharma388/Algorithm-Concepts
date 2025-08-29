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
	int n;
	cin >> n;
	int *a = new int[n];
	stack<int> s;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	s.push(a[0]);
	for(int i=1;i<n;++i){
		while(!s.empty() && s.top()<a[i]){
			cout<<a[i]<<" ";
			s.pop();
		}
		s.push(a[i]);
	}
	while(!s.empty()){
		cout<<"-1 ";
		s.pop();
	}
	return 0;
}