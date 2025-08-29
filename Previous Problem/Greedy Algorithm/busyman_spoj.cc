#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

compare(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		vector<pair<int,int>> activites;
		// taking input and storing the data into pair
		// that represents the start time of activity 
		// and end time of the activity.
		for(int i = 0; i < n; ++i){
			int s,e;
			cin >> s >> e;
			pair<int,int> act = {s,e};
			activites.push_back(act);
		}
		// sorting the activity based upon their ending time.
		sort(activites.begin(), activites.end(),compare);
		// intialising the act_count that keep track of 
		// activities we have participated in.
		int act_count = 0;
		int prevEnd = -1;
		for(int i = 0; i < n; ++i){
			if(prevEnd == -1 or prevEnd <= activites[i].first){
				prevEnd = activites[i].second;
				act_count++;
			}
		}
		cout << act_count << endl;
	}	
	return 0;
}

// Sample Input :

// 3
// 3
// 3 9
// 2 8
// 6 9
// 4
// 1 7
// 5 8
// 7 8
// 1 8

// Sample Output :

// 1
// 2
// 3