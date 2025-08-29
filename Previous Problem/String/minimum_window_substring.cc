#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string minimumWindowSubstring(string &str,string &ptr){
	int len1 = str.size();
	int len2 = ptr.size();
	if(len1 < len2) {
		return "No Window";
	}
	int hash_str[256] = {0};
	int hash_ptr[256] = {0};
	for(int i = 0; i < len2; ++i) {
		hash_ptr[ptr[i]] += 1;
	}
	int start = 0,start_index = -1,min_len = INT_MAX;
	int count = 0;
	for(int j = 0; j < len1; ++j){
		hash_str[str[j]] +=1;
		// if current element is a part of min window.
		if(hash_ptr[str[j]] !=0 and hash_ptr[str[j]] >= hash_str[str[j]]){
			count += 1;
		}
		// if we have already done with the window. 
		// then we will try to find the best one with minimum length by shrinking. 
		if(count == len2){
			while(hash_ptr[str[start]] < hash_str[str[start]] or hash_ptr[str[start]] == 0){
				if(hash_ptr[str[start]] < hash_str[str[start]]){
					hash_str[str[start]] -= 1;
				}
				start += 1;
			}
			// calculating the current length.
			int cur_len = j - start + 1;
			if(min_len > cur_len){
				// comparing current window length with minimum window length
				min_len = cur_len;
				start_index = start; 
			}
		}	
	}
	if(start_index == -1){
		return "No Window";
	}
	return str.substr(start_index,min_len);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str,ptr;
	cin >> str >> ptr;
	cout << minimumWindowSubstring(str,ptr);
	return 0;
}