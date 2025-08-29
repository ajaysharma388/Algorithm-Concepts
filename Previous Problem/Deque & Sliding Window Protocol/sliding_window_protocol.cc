#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// this is classic implementation of sliding window problem.
// we can also implement that using deque.
// current complexity of the code is.
// O(n*k) where, n is the number of elements 
// and k is the size of window. 

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n;
	int *a = new int[n];
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	cin >> k;
	int i=0;
	while(i+k<=n){
		int m = -1;
		for(int j=i;j<i+k;++j){
			m = max(m,a[j]);
		}
		cout<<m<<" ";
		i++;
	}
	cout<<endl;
	return 0;
}

// Input : 

// 9
// 1 2 3 1 4 5 2 3 6
// 3

// Output : 

// 3 3 4 5 5 5 6 