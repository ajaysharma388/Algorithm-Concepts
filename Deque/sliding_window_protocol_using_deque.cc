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
	int n,k,i;
	cin >> n;
	int *a = new int[n];
	for(int i=0;i<n;++i){
		cin >> a[i];
	}	
	cin >> k;
	deque<int> Q(k);
	for(i=0;i<k;++i){
		while(!Q.empty() && a[i]>a[Q.back()]){
			Q.pop_back();
		}
		Q.push_back(i);
	}
	for(;i<n;++i){
		// 1. printing the front element of the deque.
		cout<<a[Q.front()]<<" ";
		// 2. Remove the Element which is not in window.
		while(!Q.empty() && Q.front()<=i-k){
			Q.pop_front();
		}
		// 3. Remove all the element which are lesser than the 
		//    current element.
		while(!Q.empty() && a[i]>=a[Q.back()]){
			Q.pop_back();
		}
		// 4. Adding element at the back of deque.
		Q.push_back(i);
	}
	cout<<a[Q.front()]<<endl;
	return 0;
}

// This is a classic implementation of the sliding window protocol
// that does the job in O(n) complexity as compared to previous O(n*k)
// using Deque.

// Input : 

// 9
// 1 2 3 1 4 5 2 3 6
// 3

// Output : 

// 3 3 4 5 5 5 6