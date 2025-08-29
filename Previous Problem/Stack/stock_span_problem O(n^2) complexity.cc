#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


// first attempt implementation.

int betterPrice(int *a,int n,int i){
	stack<int> s;
	int curPrice = a[i];
	int j=0;
	while(j<i && j<n){
		s.push(a[j]);
		j++;
	}
	int days = 1;
	while(!s.empty() && curPrice>=s.top()){
		days++;
		s.pop();
	}
	return days;
}

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
		int *r = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
			r[i] = 0;
		}
		for(int i=1;i<n;++i){
			r[i] = betterPrice(a,n,i);			
		}
		for(int i=0;i<n;++i){
			cout<<r[i]<<" ";			
		}
		delete []r;
		delete []a;
	}
	return 0;
}