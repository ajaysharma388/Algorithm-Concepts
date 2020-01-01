#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int longestConsecutiveSubsequenec(int *arr,int n){
	unordered_set<int> s;
	for(int i=0; i<n; ++i){
		s.insert(arr[i]);
	}
	int ans = 0;
	for(int i=0; i<n; ++i){
		if(s.find(arr[i]-1) != s.end()){
			continue;
		} else {
			int count = 0;
			int x = arr[i];
			while(s.find(x) != s.end()){
				x++;
				count++;
			}
			ans = max(count,ans);
		}
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}	
	int result = longestConsecutiveSubsequenec(arr,n);
	cout << result << endl;
	return 0;
}

// Sample Input :

// 12
// 5 1 9 2 6 3 7 8 10 12 13 4

// 12
// 5 1 9 2 6 3 7 8 10 12 13 11

// 12
// 5 1 9 2 6 3 7 8 10 12 13 14

// Sample Output :

// 10

// 9

// 6