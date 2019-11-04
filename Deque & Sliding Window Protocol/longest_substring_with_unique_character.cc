#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// In this function we are using the sliding window protocol for 
// finding the logest sub string with unique elements.

int longestSubString(string &s){
	int visited[256];
	for(int i=0;i<256;++i){ 
		visited[i] = -1; 
	}
	int n = s.length();
	int curr_len=1,max_len=1;
	visited[s[0]] = 0;
	for(int i=1;i<n;++i){
		// expansion of the window.
		int last_occ = visited[s[i]];
		if(last_occ==-1|| i-curr_len>last_occ){
			curr_len++;
		}
		// expansion + compression of window.
		else{
			max_len = max(max_len,curr_len);
			curr_len = i-last_occ;
		}
		visited[s[i]] = i;
	}
	max_len = max(curr_len,max_len);
	return max_len;
}

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
		string input;
		cin >> input;
		cout<<longestSubString(input)<<endl;
	}
	return 0;
}

// TestCases : 

// Input : 

// 4
// cadzabcdefghij
// baaadeabc
// abzklmabx
// aaacvaaaa


// Output : 

// 11
// 5
// 7
// 3