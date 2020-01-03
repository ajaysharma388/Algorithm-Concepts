#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	char data;
	bool isTerminal;
	int count;
	unordered_map<char,node*> children;
	node(const char data){
		this->data = data;
		isTerminal = false;
		this->count = 0;
	}	
};

class trie
{
public:
	node* root;
	int wordCount = 0;
	trie(){
		this->root = new node('\0');
		wordCount = 0; 
	}
	// add the new word into the trie.
	void addWord(string str){
		node *temp = root;
		this->wordCount += 1;
		for(int i = 0; i < str.length(); ++i){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			} else {
				node *n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
			temp->count++;
		}
		temp->isTerminal = true;
	}
	// search for the input string in the trie
	bool search(string str){
		node*temp = root;
		for(int i=0; i < str.length(); ++i){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			} else {
				return false;
			}
		}
		return temp->isTerminal;
	}
	void traverse(string str){
		node*temp = root;
		for(int i=0; i < str.length(); ++i){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
				cout << temp->data << " : " << temp->count << endl;
			}
		}
	}
	string scan(string str){
		node*temp = root;
		string res = "";
		int i = 0;
		do{
			temp = temp->children[str[i]];
			res += temp->data;
			i++;
		}while(temp->count!=1);
		return res;
	}
	string* getMinimumPrefix(string*List,int list_size){
		string *result = new string[list_size];
		for(int i=0; i < list_size; ++i){
			result[i] = scan(List[i]);
		} 
		return result;
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
	trie t;
	cin >> n;
	string *list = new string[n];
	for(int i=0; i < n; ++i){
		string cur;
		cin >> cur;
		t.addWord(cur);
		list[i] = cur;
	}
	list = t.getMinimumPrefix(list,n);
	int i=0;
	cout<<"[ ";
	for(; i < n-1; ++i){
		cout << list[i] << ", ";
	}
	cout<<list[i]<<" ]"<<endl;
	return 0;
}

// Sample Input :

// 10
// redtape
// redis
// redhat
// turmaric
// italiano
// paying
// payne
// zebra
// ajay
// ankush

// Sample Output :

// [ redt, redi, redh, t, i, payi, payn, z, aj, an ]