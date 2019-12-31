#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

typedef pair<int,pair<int,int>> customPair;

vector<int> mergeKSortedArray(vector<vector<int>> &arr){
	vector<int> result;
	priority_queue<customPair,vector<customPair>,greater<customPair>> pq;
	for(int i=0; i<arr.size(); ++i){
		pq.push({ arr[i][0], { i, 0}});
	}
	while(!pq.empty()){
		customPair cur = pq.top();
		pq.pop();
		result.push_back(cur.first);
		int x = cur.second.first;
		int y = cur.second.second + 1;
		if(y < arr[x].size()){
			pq.push({ arr[x][y], { x, y}});
		}
	}
	return result;
} 

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,n;
	cin >> k >> n;
	vector<vector<int>> arr(k);
	for(int i=0; i<k; ++i){
		for(int j=0; j<n; ++j){
			int data;
			cin >> data;
			arr[i].push_back(data);
		}
	}	
	vector<int> vec = mergeKSortedArray(arr);
	for(int i=0; i<vec.size(); ++i){
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}

// Sample Input :

// 4 5
// 4 5 9 12 25
// 1 3 7 8 21
// 2 6 10 11 13
// 0 14 17 22 24

// Sample Output :

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 17 21 22 24 25 