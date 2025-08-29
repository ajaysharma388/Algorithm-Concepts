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
	int t;
	cin >> t;
	while(t--){
		unordered_map<int,bool> array;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			int data;
			cin >> data;
			array[data] = true;
		}
		int q;
		cin >> q;
		while(q--){
			int data;
			cin >> data;
			if(array.find(data)!=array.end()){
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
	}	
	return 0;
}

// Sample Input : 

// 1
// 6
// 12 3 -67 67 34 2
// 4
// 4
// 5
// 67
// 7

// Sample Output :

// No
// No
// Yes
// No