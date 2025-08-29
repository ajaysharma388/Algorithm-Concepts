#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool compare(pair<int,int> a,pair<int,int> b){
	return (a.second/a.first) > (b.second/b.first);
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
	vector<pair<int,int>> itemList;
	for(int i = 0; i < n; ++i){
		int w,p;
		cin >> w >> p;
		pair<int,int> item = {w,p};
		itemList.push_back(item);
	}	
	int capacity,i=0,profit=0;
	cin >> capacity;
	sort(itemList.begin(), itemList.end(), compare);
	while(capacity){
		if(capacity>=itemList[i].first){
			capacity -= itemList[i].first;
			profit += itemList[i].second;
		} else if(capacity > 0){
			profit += capacity*(itemList[i].second/itemList[i].first);
			capacity = 0;
		}
		i++;
	}
	cout << "Maximum profit that theif can make " << profit << endl;
	return 0;
}

// Sample Input :

// 5
// 7 550
// 4 110
// 5 100
// 3 190
// 2 200
// 8

// 3
// 3 90
// 5 100
// 2 200
// 6 

// Sample output :

// Maximum profit that theif can make 668

// Maximum profit that theif can make 310