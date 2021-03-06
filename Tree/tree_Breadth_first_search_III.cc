#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(const int d){
		data = d;
		left = NULL;
		right = NULL;
	}
	~Node();
};

#define pni pair<Node*,int>
// This implementation does'nt take the root pointer as the input.
// and at the end of the processing it returns the address of new root 
// node.

Node* build(){
	int data;
	cin >> data;
	if(data==-1){
		return NULL;
	}
	Node* root = new Node(data);
	root->left = build();
	root->right = build();
	return root;
}

// This implementation takes the root pointer as the input and at 
// the end of the processing it returns the address of same root 
// node that it gets from the user.

Node* buildTree(Node* root){
	int data;
	cin >> data;
	if(data==-1) return NULL;
	root = new Node(data);
	root->left = buildTree(root->left);
	root->right = buildTree(root->right);
	return root;
}

// Breadth first Search Or Level order Traversal 
// Time complexty is reduced from O(n^2) -> o(n).

void levelOrder(Node* root){
	if(root == NULL) return;
	queue<pni> Q;
	int l = 1;
	int cLevel = l;
	pni t = make_pair(root,l);
	Q.push(t);
	while(!Q.empty()){
		pni p = Q.front();
		Node* f = p.first;
		if(cLevel!=p.second){
			cout<<endl;
			cLevel = p.second;
		}
		cout<<f->data<<" ";
		if(f->left){
			t = make_pair(f->left,cLevel+1);
			Q.push(t);
		}
		if(f->right){
			t = make_pair(f->right,cLevel+1);
			Q.push(t);
		}
		Q.pop();
	}
}



int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = NULL;
	root = build();
	levelOrder(root);
	return 0;
}



// TestCases.

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1
// 8 10 1 -1 -1 -1 3 6 9 -1 -1 7 -1 -1 14 13 -1 -1

// Output :  

// Level Order : 3 4 9 5 8 10 6 7 11 12 13 14 
// Level Order : 8 10 3 1 6 14 9 7 13 