#include <bits/stdc++.h>
#include "trie.h"
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
	trie t;
	int n;
	cin >> n;
	while(n--){
		string word;
		cin >> word;
		t.addWord(word);
	}	
	int q;
	cin >> q;
	while(q--){
		string query;
		cin >> query;
		if(t.search(query)){
			cout << query << " Exist." << endl;
		} else {
			cout << query << " Not Exist." << endl;
		}
	}
	return 0;
}

// Sample Input :

// 10 
// apple
// api
// appy
// boy
// boycott
// player
// playing
// window10
// windiesel
// cristin
// 5
// boy
// martin
// apple
// grey
// window10

// Sample Output :

// boy Exist.
// martin Not Exist.
// apple Exist.
// grey Not Exist.
// window10 Exist.