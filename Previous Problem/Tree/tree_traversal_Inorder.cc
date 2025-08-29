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

Node* buildTree(Node* root){
	int data;
	cin >> data;
	if(data==-1) return NULL;
	root = new Node(data);
	root->left = buildTree(root->left);
	root->right = buildTree(root->right);
	return root;
}

// code for the inorder traversal of the tree.

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
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
	cout<<" In Order : ";
	inorder(root);
	return 0;
}



// TestCases.

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1
// 8 10 1 -1 -1 -1 3 6 9 -1 -1 7 -1 -1 14 13 -1 -1

// Output :  
 
//  In Order : 6 5 7 4 8 3 9 11 10 13 12 14 

//  In Order : 1 10 8 9 6 7 3 13 14 
