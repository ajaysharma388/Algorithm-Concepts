#include <bits/stdc++.h>
#include "hashtable.h"
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
	int n;
	cin >> n;
	HashTable<int> ht;
	while(n--){
		int price;
		string fruit;
		cin >> fruit >> price;
		ht.insert(fruit,price);
	}
	ht.print();
	ht.Delete("Apple");
	cout<<"--------------Removed : Apple-----------------"<<endl;
	ht.print();
	ht.Delete("Grapes");
	cout<<"--------------Removed : Grapes-----------------"<<endl;
	ht.print();
	cout<<"--------------Searching : Chicku-----------------"<<endl;
	int *price = ht.search("Chicku");
	cout<<" Chicku : "<<*price<<endl;
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


// 1 . bucket [0] => Pomegrant Mango 
// 2 . bucket [1] => Orange 
// 3 . bucket [2] => Lichi 
// 4 . bucket [3] => 
// 5 . bucket [4] => Guava Apple 
// 6 . bucket [5] => Grapes Banana 
// 7 . bucket [6] => Chicku PineApple 
// --------------Removed : Apple-----------------
// 1 . bucket [0] => Pomegrant Mango 
// 2 . bucket [1] => Orange 
// 3 . bucket [2] => Lichi 
// 4 . bucket [3] => 
// 5 . bucket [4] => Guava 
// 6 . bucket [5] => Grapes Banana 
// 7 . bucket [6] => Chicku PineApple 
// --------------Removed : Grapes-----------------
// 1 . bucket [0] => Pomegrant Mango 
// 2 . bucket [1] => Orange 
// 3 . bucket [2] => Lichi 
// 4 . bucket [3] => 
// 5 . bucket [4] => Guava 
// 6 . bucket [5] => Banana 
// 7 . bucket [6] => Chicku PineApple 
// --------------Searching : Chicku-----------------
//  Chicku : 80
