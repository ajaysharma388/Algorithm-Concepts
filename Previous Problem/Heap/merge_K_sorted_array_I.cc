#include <bits/stdc++.h>
using namespace std;

// current code can only merge the 3 sorted arrays
// using the heap.

// we have the different implementation for the merge
// k sorted arrays in the heap section of this repository 

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
	int N,K;
	cin >> K >> N;
	int *arr = new int[K*N];
	for(int i=0;i<N*K;++i){
		cin >> arr[i];
	}
	int m=0,n=N,o=2*N;
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(arr[m]);
	pq.push(arr[n]);
	pq.push(arr[o]);
	vector<int> result; 
	while(m!=N and n!=2*N and o!=3*N){
		int cur = pq.top();
		pq.pop();
		if(arr[m]==cur){
			m++;
			pq.push(arr[m]);
		}else if(arr[n]==cur){
			n++;
			pq.push(arr[n]);
		}else{
			o++;
			pq.push(arr[o]);
		}
		result.push_back(cur);
	}	
	while(!pq.empty()){
		result.push_back(pq.top());
		pq.pop();
	}
	delete []arr;
	for(int i=0;i<N*K;++i){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}