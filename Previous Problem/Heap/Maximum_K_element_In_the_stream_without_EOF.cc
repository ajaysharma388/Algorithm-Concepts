#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define pqi priority_queue<int,vector<int>,greater<int>>


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 5;
	pqi pq;
	int data;
	while(cin >> data && data!=-1){
		if(pq.size()<k){
			pq.push(data);
		}else{
			pq.pop();
			pq.push(data);
		}
	}
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}

// Input : 

// 5
// 3 2 4 1 5 4 7 11 19 22 36 12 91 156 222 99 82 71 111 169 215 1811 23 1468 12 36 1211 -1

// Output : 

// 215 222 1211 1468 1811 
