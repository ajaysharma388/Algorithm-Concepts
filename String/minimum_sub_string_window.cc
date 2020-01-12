#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


string min_substr(string text,string ptr){
	int txt_len = text.length();
	int ptr_len = ptr.length();
	if(ptr_len > txt_len) return "No string";
	int match = 0;
	int txt_fre[256] = {0};
	int ptr_fre[256] = {0};
	// Creating the frequency map of pattern.
	for(int i = 0; i < ptr_len; ++i){
		ptr_fre[ptr[i]] += 1;
	}
	int i = 0;
	int j = 0;
	int min_len = txt_len;
	int start = 0;
	for(; j < txt_len; ++j){
		txt_fre[text[j]]++;
		if(ptr_fre[text[j]] >= txt_fre[text[j]] and ptr_fre[text[j]]){
			match++;
		}
		while(match == ptr_len){
			if(ptr_fre[text[i]] < txt_fre[text[i]]){
				txt_fre[text[i]]--;
				i++;
			} else{
				if(min_len > j - i + 1){
					start = i;
					min_len = j - i + 1;
				}
				break;
			}
		}
	}
	if(match != ptr_len) return "No string";
	return text.substr(start , min_len);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string text,ptr;
	getline(cin ,text);
	getline(cin ,ptr);
	cout << min_substr(text,ptr) << endl;
	return 0;
}

// Sample Input :

// qwerty asdfgh qazxsw
// qas

// abcdeafcbghi
// bcg

// Sample Output :

// qas
// cbg