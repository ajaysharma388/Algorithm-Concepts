#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string getKthToken(string s,int key) {
	// we will use the strtok() method.
	char *ptr = strtok((char *)s.c_str()," ");
	while(key > 1) {
		ptr = strtok(NULL," ");
		key--;												
	}
	return (string)ptr;
}

int convertToInt(string s) {
	int ans = 0;
	int p = 1;
	for(int i = s.length() - 1; i >= 0; --i) {
		ans += ((s[i]-'0')*p);
		p *= 10;
	}
	return ans;
}

bool numericCompare(pair<string,string> s1,pair<string,string> s2) {
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return convertToInt(key1) < convertToInt(key2);
}

bool lexicoCompare(pair<string,string> s1,pair<string,string> s2) {
	string key1,key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1 < key2;
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
	cin.get();
	string arr[100];
	for(int i = 0; i < n; ++i) {
		getline(cin,arr[i]);
	}	
	int key;
	string reversal,ordering;
	cin >> key >> reversal >> ordering;
	pair<string,string> strPair[100];
	for(int i = 0; i < n; ++i) {
		strPair[i].first = arr[i];
		strPair[i].second = getKthToken(arr[i],key);
	}
	// if the ordering is numeric.
	if(ordering == "numeric") {
		sort(strPair ,strPair+n ,numericCompare );
	} else {
		sort(strPair ,strPair+n ,lexicoCompare );
	}
	// if reversal is true the we will simple reverse the result.
	if(reversal == "true") {
		for(int i = 0; i < n/2; ++i) {
			swap(strPair[i],strPair[n-i-1]);
		}	
	}
	// Printing the content.
	for(int i = 0; i < n; ++i) {
		cout << strPair[i].first << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 92 022
// 82 12
// 77 13
// 2 false numeric

// Sample Output :

// 82 12
// 77 13
// 92 022