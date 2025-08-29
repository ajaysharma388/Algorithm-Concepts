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
	priority_queue<int,vector<int>,greater<int>> pq;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int cur;
		cin >> cur;
		pq.push(cur);
	}
	while(pq.size()>1){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		pq.push(first+second);
	}
	cout<<pq.top()<<endl;
	return 0;
}