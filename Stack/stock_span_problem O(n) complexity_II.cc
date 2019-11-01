#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// without using pair O(n) complexity.

void stockSpanPrice(int n,int *a){
	stack<int> stock;
	int *ans = new int[n];
	for(int day=0;day<n;++day){
		int currPrice = a[day];
		while(!stock.empty() && a[stock.top()]<currPrice){
			stock.pop();
		}
		int betterDay = (stock.empty())?0:stock.top();
		int span = day - betterDay;
		ans[day] = span;
		stock.push(day);
	}
	for(int i=0;i<n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	delete []ans;
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
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		stockSpanPrice(n,a); 
		delete []a;
	}
	return 0;
}