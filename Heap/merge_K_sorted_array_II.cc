#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define pii pair<int*,int>
#define ppi pair<int,pii>
#define mp make_pair
#define pb push_back

class compare{
public:
	bool operator()(ppi a,ppi b){
		return a.first > b.first;
	}
};

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
	// allocating memory for the 2d array of row k.
	int **arr = new int*[k];
	// allocating the array of size n.
	for(int i=0;i<k;++i){
		arr[i] = new int[n];
	}
	for(int i=0;i<k;++i){
		for(int j=0;j<n;++j){
			cin >> arr[i][j];
		}
	}
	// result will be stored in it.
	vector<int> result;
	// priority_queue for storing the ppi uses compare's 
	// ()oprator to maintain the min heap. 
	priority_queue<ppi,vector<ppi>,compare> pq;
	int it = 0;
	for(int i=0;i<k;++i){
		pq.push(mp(arr[i][0],mp(arr[i],0)));
	}
	while(it < n*k){
		int fs = pq.top().first;
		auto sec = pq.top().second;
		int *ptr = sec.first;
		int idx = sec.second+1;
		int data = *(ptr+idx);
		cout<<fs<<" ";
		pq.pop();
		result.pb(fs);
		pq.push(mp(data,mp(ptr,idx)));
		it++;  
	}
	for(int i=0;i<k;++i){
		delete []arr[i];
	}
	delete []arr;
	return 0;
}
// this is coding implementation for the merge k sorted array
// into single sorted array we can also use the merge sort 
// algorithm but the time complexity for the merge sort algorithm 
// O(NlogN) here, N would be equal to n*k but using heap we can 
// solve the same problem in the O(nklogk) which is much better
// than the complexity of merge sort algorithm 

// Sample Input :

// 4 5
// 4 5 9 12 25
// 1 3 7 8 21
// 2 6 10 11 13
// 0 14 17 22 24

// sample Output :

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 17 21 22 24 25 