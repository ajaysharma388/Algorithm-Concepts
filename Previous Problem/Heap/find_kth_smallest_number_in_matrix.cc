#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
typedef pair<int,pair<int,int>> customPair;

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<int,bool> visited;
	priority_queue<customPair,vector<customPair>,greater<customPair>> pq;
	int m,n,k;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0; i<m; ++i){
		arr[i] = new int[n];
	}
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cin >> arr[i][j];
		}
	}
	cin >> k;
	int i=0;
	int j=0;
	int count = 1;
	customPair cur;
	pq.push({arr[i][j],{i,j}});
	visited[arr[i][j]] = true;
	while(count < k){
		cur = pq.top();
		// cout << cur.first << " ";
		pq.pop();
		count++;
		i = cur.second.first;
		j = cur.second.second;
		if(j+1<n and visited.find(arr[i][j+1])==visited.end()){
			pq.push({arr[i][j+1],{i,j+1}});
			visited[arr[i][j+1]] = true;
		}
		if(i+1<m and visited.find(arr[i+1][j])==visited.end()){
			pq.push({arr[i+1][j],{i+1,j}});
			visited[arr[i+1][j]] = true;
		}
	}
	cout << pq.top().first << endl;
	// Deallocating Memory.
	for(i=0; i<m; ++i){
		delete []arr[i];
	}	
	delete []arr;
	return 0;
}

// Sample Input : 

// 4 4
// 10 20 30 40 
// 15 25 35 45
// 24 29 37 48
// 32 33 39 50
// 12

// Key for ans

// {	
// 		1:10 2:15 3:20 4:24 
// 		5:25 6:29 7:30 8:32 
// 		9:33 10:35 11:37 12:39
// 		13:40 14:45 15:48 16:50
// }

// Sample Output :

// 39