#include <unordered_map>
using namespace std;

class node
{
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*> children;
	node(const char data){
		this->data = data;
		isTerminal = false;
	}	
};

class trie
{
public:
	node* root;
	trie(){
		this->root = new node('\0'); 
	}
	// add the new word into the trie.
	void addWord(string str){
		node *temp = root;
		for(int i = 0; i < str.length(); ++i){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			} else {
				node *n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
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
};