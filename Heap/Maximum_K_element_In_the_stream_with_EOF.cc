#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define pqi priority_queue<int,vector<int>,greater<int>>

void print(pqi p){
	while(!p.empty()){
		cout<<p.top()<<" ";
		p.pop();
	}
	cout<<endl;
}

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
	while(scanf("%d",&data)!=EOF){
		if(data == -1){
			print(pq);
		}
		else if(pq.size()<k){
			pq.push(data);
		}else{
			pq.pop();
			pq.push(data);
		}
	}
	print(pq);
	return 0;
}

// Input : 

// 5 3 2 4 1 5 4 7 -1 11 19 22 36 -1 12 91 156 -1 222 99 82 71 111 169 215 -1 1811 23 1468 12 36 1211 -1 

// Output : 

// 215 222 1211 1468 1811 

// 4 4 5 5 7 
// 7 11 19 22 36 
// 19 22 36 91 156 
// 111 156 169 215 222 
// 215 222 1211 1468 1811 
// 215 222 1211 1468 1811 