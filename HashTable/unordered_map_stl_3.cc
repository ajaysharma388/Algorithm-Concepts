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
		fruits.insert(make_pair(fruit,price));
	}	
	auto size = fruits.bucket_count();
	for(auto i=0;i<size;++i){
		cout<<" Bucket No : "<< i << " => ";
		for(auto it = fruits.begin(i);it!=fruits.end(i);++it){
			cout<<" "<< it->first << " : " << it->second << " | "; 
		} 
		cout<<" End Of Bucket No : " << i << endl;
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

//  Bucket No : 0 =>  Mango : 82 |  End Of Bucket No : 0
//  Bucket No : 1 =>  End Of Bucket No : 1
//  Bucket No : 2 =>  End Of Bucket No : 2
//  Bucket No : 3 =>  End Of Bucket No : 3
//  Bucket No : 4 =>  Lichi : 70 |  End Of Bucket No : 4
//  Bucket No : 5 =>  End Of Bucket No : 5
//  Bucket No : 6 =>  End Of Bucket No : 6
//  Bucket No : 7 =>  End Of Bucket No : 7
//  Bucket No : 8 =>  Grapes : 90 |  Orange : 40 |  Banana : 55 |  End Of Bucket No : 8
//  Bucket No : 9 =>  End Of Bucket No : 9
//  Bucket No : 10 =>  Chicku : 80 |  Pomegrant : 100 |  Guava : 50 |  End Of Bucket No : 10
//  Bucket No : 11 =>  End Of Bucket No : 11
//  Bucket No : 12 =>  Apple : 80 |  End Of Bucket No : 12
//  Bucket No : 13 =>  End Of Bucket No : 13
//  Bucket No : 14 =>  PineApple : 80 |  End Of Bucket No : 14
//  Bucket No : 15 =>  End Of Bucket No : 15
//  Bucket No : 16 =>  End Of Bucket No : 16