#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// finds area under historgram using stack in O(n) complexity.
// which is quit good interms of it's brute force and divide and conquer
// approach.

int largestArea(int *a,int n){
	stack<int> s;
	int area = -1;
	s.push(0);
	for(int i=1;i<n;++i){
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
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	cout<<largestArea(a,n)<<endl;
	delete []a;	
	return 0;
}