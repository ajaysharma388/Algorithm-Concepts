#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	char data;
	map<char,node*> children;
	bool is_terminal;
	node(const char data){
		this->data = data;
		this->is_terminal = false;
	}
};

class trie{
	vector<string> res;
	void find(node*root,string cur=""){
		// if this is the ending node.
		if(root->is_terminal){
			res.push_back(cur+root->data);
			if(root->children.empty()) return;
		}
		// else we have cur node which is not ending;
		for(auto node:root->children){
			string s = cur+root->data;
			find(node.second,s);
		}
		return;
	}
public:
	node*root;
	trie(){
		this->root = new node('\0');		
	}
	void insert(const string s){
		int len = s.length();
		node*temp = root;
		for(int i = 0; i < len; ++i){
			char cur = s[i];
			if(temp->children.count(cur)){
				temp = temp->children[cur];
			} else {
				node *n = new node(cur);
				temp->children[cur] = n;
				temp = n;
			}
		}
		temp->is_terminal = true;
	}
	bool search(const string s){
		int len = s.length();
		node*temp = root;
		for(int i = 0; i < len; ++i){
			char cur = s[i];
			if(temp->children.find(cur)!=temp->children.end()){
				temp = temp->children[cur];
			} else {
				return false;
			}
		}
		if(temp->is_terminal){
			cout << s << endl;
		}
		for(auto node:temp->children){
			// code for all possible combinations
			find(node.second);
			for(int i = 0; i < res.size(); ++i){
				cout << s << res[i] << endl;
			}
			res.clear();
		}
		return true;
	}
};


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
	trie dic;
	while(n--){
		string word;
		cin >> word;
		dic.insert(word);
	}
	cin >> n;
	while(n--){
		string pre;
		cin >> pre;
		if(!dic.search(pre)){
			cout << "No suggestions" << endl;
			dic.insert(pre);
		}
	}
	return 0;
}

// Sample Input :

// 10
// pet
// peter
// petar
// petrol
// rat
// rack
// ratrica
// randy
// ranbaxy
// rajesh
// 3
// r
// p
// pett

// Sample Output :

// rack
// rajesh
// ranbaxy
// randy
// rat
// ratrica
// pet
// petar
// peter
// petrol
// No suggestions