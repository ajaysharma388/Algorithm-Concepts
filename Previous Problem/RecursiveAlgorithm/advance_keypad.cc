#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string table[] = { " ", ".+@$", "abc", "def", "ghi", 
			"jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = {
			   "prateek", "sneha", "deepak", 
			   "arnav", "shikha", "palak",
			   "utkarsh", "divyam", "vidhi",
			   "sparsh", "akku"
   			};


// this method takes O(sa*sb) to find whether the a is substring of b or not

bool substring(string &a,string &b) {
	int sa = a.length();
	int sb = b.length();
	for(int i = 0; i < sb-sa ; ++i) {
		if(b[i] == a[0]) {
			int count = 1;
			for(int j = 1; j < sb; ++j){
				if(a[j] != b[i+j]) break;
				else count++;
			}
			if(count == sa) return true;
		}
	}
	return false;
}

vector<string> res;
void formString(string a,string b) {
	for(int i = 0; i < a.length(); ++i) {
		for(int j = 0; j < b.length(); ++j) {
			string s = "";
			s += a[i];
			s+=b[j];
			res.push_back(s);
		}
	}
}

void append(string s){
	vector<string> result;
	for(auto i:s) {
		for(auto j:res){
			result.push_back(j+i);
		}
	}
	res = result;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string inp;
	cin >> inp;
	string a = table[inp[0]-'0'];
	string b = table[inp[1]-'0'];
	formString(a,b);
	for(int i = 2; i < inp.length(); ++i){
		append(table[inp[i]-'0']);
	}
	bool in[11] = {false}; 
	for(int i = 0; i < res.size(); ++i){
		for(int j = 0; j < 11; ++j) {
			if(substring(res[i],searchIn[j]) and !in[j]) {
				cout << searchIn[j] << endl;
				in[j] = 1;
			}
		}
	}
	return 0;
}

// Sample Input :

// 34

// Sample Output :

// vidhi
// divyam
// sneha