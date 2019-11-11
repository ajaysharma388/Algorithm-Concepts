#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// without using pair O(n) complexity.
// Implementation done by mentor.

void stockSpan(int n,int *a){
	stack<int> s;
	int *res = new int[n];
	// code here.
	for(int i=0;i<n;++i){
		cout<<res[i]<<" ";
	}
	cout<<"END";
}

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
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	stockSpan(n,a);
	delete []a;
	return 0;
}
