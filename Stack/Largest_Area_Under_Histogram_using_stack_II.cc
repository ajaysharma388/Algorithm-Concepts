#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// finds area under historgram using stack in O(n) complexity.
// which is quit good interms of it's brute force and divide and conquer
// approach.

ll largestArea(int *a,int n){
	stack<int> s;
	ll area = -1;
	s.push(0);
	for(ll i=1;i<n;++i){
		int currElement = a[i];
		if(currElement<a[s.top()]){
			int minBar = a[s.top()];
			while(currElement<minBar){
				s.pop();
				if(!s.empty()){
					area = max(area,minBar*(i-s.top()-1));
					minBar = a[s.top()];
				}else{
					area = max(area,minBar*i);
					break;
				}
			}
			s.push(i); 
		}else{
			s.push(i);
		} 
	}
	return area;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases,n;
	cin >> testCases;
	while(testCases--){
		cin >> n;
		int *a = new int[n+1];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		a[n] = -1;
		cout<<largestArea(a,n+1)<<endl;
		delete []a;
	}	
	return 0;
}



// Input : 

// 3
// 7
// 6 2 2 2 3 3 6
// 5
// 1 2 3 4 5
// 7
// 10 40 30 70 10 30 60

// Output

// 14
// 9
// 90