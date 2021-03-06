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
	priority_queue<int,vector<int>,greater<int>> pq; // process to create min heap.
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for(int i=0;i<10;++i){
		pq.push(a[i]);
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	delete []a;	
	return 0;
}

// Input : 

// 10
// 5 6 17 18 9 11 8 2 3 20

// Output : 

// 2 3 5 6 8 9 11 17 18 20  