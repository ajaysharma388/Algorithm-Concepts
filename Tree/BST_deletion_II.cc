#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// data structure that represents the node of the Binary Tree Data
// Structure.

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
};

// This method takes root and data as the argument and insert's 
// the new node in tree with the data given in an argument in a 
// ordered fashion.

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

// Main Method that will be called to build the Binary Search Tree.
// it uses the above method insertInBST to do so.

Node* buildBST(){
	Node*root = NULL;
	int n;
	cin >> n;
	for(int i=0;i<n;++i) {
		int data;
		cin >> data;
		root = insertInBST(root,data);
	}
	return root;
}


// Breadth first Search Or Level order Traversal 
// Time complexty is O(n).

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

// Method for the inorder traversal of the binary tree.

void preorder(Node*root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

// This method will be used to delete the node from the Binary 
// Search tree if it is present in the tree.


Node* deleteInBST(Node*root,int data){
	// Base Case if the root is empty we are supposed to return NULL.
	if(root==NULL) return NULL;
	// If the data is smaller than the root then it will be 
	// present in the left sub-tree. 
	else if(root->data > data){
		root->left = deleteInBST(root->left,data);
		return root;
	}
	// Now if the data is equal to the current node's data.
	else if(root->data==data){
		// 1. if the root has zero childrens.
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		// 2. if root has one children.
		// Left children is present.
		if(root->left!=NULL && root->right==NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		// right children is present.
		if(root->left==NULL && root->right!=NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}
		// 3. If the root has both the childrens available.
		Node *replace = root->right;
		while(replace->left!=NULL){
			replace = replace->left;
		} 
		root->data = replace->data;
		root->right = deleteInBST(root->right,replace->data);
		return root;
	}
	// If the data is larger than the root then it will be 
	// present in the right sub-tree. 
	else{
		root->right = deleteInBST(root->right,data);
		return root;
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
	int TestCases;
	cin >> TestCases;
	while(TestCases--){
		Node* root = buildBST();
		int m;
		cin >> m;
		while(m--){
			int element;
			cin >> element;
			root = deleteInBST(root,element);
		}
		preorder(root);
	}
	return 0;
}



// TestCases.

// Input : 

// 1
// 7
// 5 3 2 4 7 6 8
// 3
// 2 3 5

// Output :  

// 6 4 7 8