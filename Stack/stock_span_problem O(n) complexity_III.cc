#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// without using pair O(n) complexity.
// Implementation done by mentor.

void stockSpan(int n,int *a){
	stack<int> s;
	int *res = new int[n];
	for(int i=0;i<n;++i){
		while(!s.empty() && a[i]>=a[s.top()]){
			s.pop();
		}
		if(s.empty()){
			res[i] = i+1;
		}else{
			res[i] = i-s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;++i){
		cout<<res[i]<<" ";
	}
	cout<<"END"<<endl;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while(testCase--){
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		stockSpan(n,a);
		delete []a;
	}
	return 0;
}
