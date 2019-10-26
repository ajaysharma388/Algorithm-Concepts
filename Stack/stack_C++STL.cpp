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
	stack<string> fruits;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		string fruit;
		cin >> fruit;
		fruits.push(fruit);
	}
	while(!fruits.empty()){
		cout<<fruits.top()<<endl;
		fruits.pop();
	}
	return 0;
}

// input : 

// 5
// Apple
// Banana
// Mango
// Grapes
// Orange

// output : 

// Orange
// Grapes
// Mango
// Banana
// Apple

