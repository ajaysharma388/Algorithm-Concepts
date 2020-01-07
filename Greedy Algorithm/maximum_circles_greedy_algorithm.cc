#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool compare(pair<int,int> coordsA,pair<int,int> coordsB){
	return coordsA.second < coordsB.second; 
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
	vector<pair<int,int>> circles;
	for(int i = 0; i < n; ++i){
		int x,r;
		cin >> x >> r;
		pair<int,int> coords = {x-r,x+r};
		circles.push_back(coords);
	}	
	sort(circles.begin(), circles.end(), compare);
	int endCords = -1;
	int count = 0;
	for(auto i = 0; i < n; ++i){
		if(endCords == -1 or endCords <= circles[i].first){
			endCords = circles[i].second;
			count += 1;
		}
 	}
 	cout << (n-count) << endl;
	return 0;
}

// Sample Input :

// 4
// 1 1
// 2 1
// 3 1
// 4 1

// Sample Output : 

// 3