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
	unordered_map<string,int> fruits;
	int n;
	cin >> n;
	while(n--){
		int price;
		string fruit;
		cin >> fruit >> price;
		fruits[fruit] = price;
	}	
	// printing the nodes.
	for(auto node : fruits){
		cout << node.first << " : " << node.second << endl;
	}
	return 0;
}

// Sample Input : 

// 10
// Apple 80
// Banana 55
// Lichi 70
// PineApple 80
// Mango 82
// Guava 50
// Orange 40
// Grapes 90
// Pomegrant 100
// Chicku 80

// Sample Output : 

// Grapes : 90
// Orange : 40
// Banana : 55
// Apple : 80
// Lichi : 70
// PineApple : 80
// Mango : 82
// Chicku : 80
// Pomegrant : 100
// Guava : 50