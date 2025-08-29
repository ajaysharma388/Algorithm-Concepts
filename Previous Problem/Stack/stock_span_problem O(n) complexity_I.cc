#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define pii pair<int,int>
#define mp make_pair

// time complexity of this solution is O(n) but uses pair.

void computeBetterPrice(int n,int *a,int *r){
	stack<pii> stock;
	pii p;
	p = mp(0,a[0]);
	stock.push(p);
	for(int i=1;i<n;++i){
		p = stock.top();
		pii t;
		while(!stock.empty() && p.second<=a[i]){
			stock.pop();
			p = stock.top();
		}
		r[i] = i-p.first;
		t = mp(i,a[i]);
		stock.push(t);
	}
	return;
}

// without using pair O(n) complexity.

void stockSpanPrice(int n,int *a,int *r){
	stack<int> stock;
	stock.push(0);
	for(int i=1;i<n;++i){
		int topIndex = stock.top();
		while(!stock.empty() && a[topIndex]<=a[i]){
			stock.pop();
			topIndex = stock.top();
		}
		r[i] = i-topIndex;
		stock.push(i);
	}
	return;
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
		// computeBetterPrice(n,a,r); uses pair.
		stockSpanPrice(n,a,r); // without pair implementation.
		for(int i=0;i<n;++i){
			cout<<r[i]<<" ";			
		}
		delete []r;
		delete []a;
	}
	return 0;
}