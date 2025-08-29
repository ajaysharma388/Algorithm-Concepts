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
	cin >> n;
	while(n--){
		int price;
		string fruit;
		cin >> fruit >> price;
		ht.insert(fruit,price);
	}
	ht.Delete("Apple");
	cout<<"--------------Removed : Apple-----------------"<<endl;
	ht.Delete("Grapes");
	cout<<"--------------Removed : Grapes-----------------"<<endl;
	ht.print();
	cout<<"--------------Searching : Chicku-----------------"<<endl;
	int *price = ht.search("Chicku");
	cout<<" Chicku : "<<*price<<endl;
	ht["Chicku"] = 100;
	cout<<"--------------Searching : Chicku-----------------"<<endl;
	price = ht.search("Chicku");
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


//  load factor is : 0.857143
// 1 . bucket [0] => Lichi 
// 2 . bucket [1] => PineApple 
// 3 . bucket [2] => 
// 4 . bucket [3] => 
// 5 . bucket [4] => Banana 
// 6 . bucket [5] => 
// 7 . bucket [6] => 
// 8 . bucket [7] => 
// 9 . bucket [8] => Apple 
// 10 . bucket [9] => 
// 11 . bucket [10] => Mango Guava 
//  load factor is : 0.909091
// --------------Removed : Apple-----------------
// --------------Removed : Grapes-----------------
// 1 . bucket [0] => 
// 2 . bucket [1] => 
// 3 . bucket [2] => PineApple 
// 4 . bucket [3] => 
// 5 . bucket [4] => 
// 6 . bucket [5] => 
// 7 . bucket [6] => Chicku Lichi 
// 8 . bucket [7] => Guava 
// 9 . bucket [8] => Mango Banana 
// 10 . bucket [9] => 
// 11 . bucket [10] => 
// 12 . bucket [11] => 
// 13 . bucket [12] => Pomegrant Orange 
// --------------Searching : Chicku-----------------
//  Chicku : 80
// --------------Searching : Chicku-----------------
//  Chicku : 100