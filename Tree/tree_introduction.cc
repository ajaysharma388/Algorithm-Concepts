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

// code for the preorder traversal of the tree.

void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

// code for the inorder traversal of the tree.

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

// code for the postorder traversal of the tree.

void postorder(Node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
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
	cout<<" Pre Order : ";
	preorder(root);
	cout<<endl<<" In Order : ";
	inorder(root);
	cout<<endl<<" Post Order : ";
	postorder(root);
	return 0;
}



// TestCases.

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1

// Output :  

//  Pre Order : 3 4 5 6 7 8 9 10 11 12 13 14 
//  In Order : 6 5 7 4 8 3 9 11 10 13 12 14 
//  Post Order : 6 7 5 8 4 11 13 14 12 10 9 3 