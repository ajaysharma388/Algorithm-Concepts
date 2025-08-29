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


Node* insertInBST(Node* root,int data){
	if(root==NULL){
		return new Node(data);
	}
	if(root->data>=data){
		root->left = insertInBST(root->left,data);
	}else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}


Node* insertInBst(Node*root,Node*t){
	if(root==NULL){
		return t;
	}
	if(t->data<=root->data){
		root->left = insertInBst(root->left,t);
	}else{
		root->right = insertInBst(root->right,t);
	}
	return root;
}



Node* buildBST(){
	int data;
	Node* root = NULL;
	while(cin>>data && data!=-1){
		root = insertInBST(root,data);
	}
	return root;
}


Node* buildTree(){
	int data;
	Node* root = NULL;
	while(cin>>data && data!=-1){
		Node *n = new Node(data);
		root = insertInBst(root,n);
	}
	return root;
}

// Breadth first Search Or Level order Traversal 
// Time complexty is reduced from O(n^2) -> o(n).

void levelOrder(Node* root){
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		Node* f = Q.front();
		if(f==NULL){
			Q.pop();
			cout<<endl;
			if(!Q.empty()){ Q.push(NULL); }
		}else{
			cout<<f->data<<" ";
			if(f->left){
				Q.push(f->left);
			}
			if(f->right){
				Q.push(f->right);
			}
			Q.pop();
		}
	}
}

void inorder(Node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
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
	root = buildBST();
	inorder(root);
	cout<<endl;
	levelOrder(root);
	return 0;
}



// TestCases.

// Input : 

// 8 10 1 3 6 9 7 14 13 -1

// Output :  

// 8 
// 1 10 
// 3 9 14 
// 6 13 
// 7 