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


class Pair
{
public:
	int height,diameter;
	Pair(){
		height = 0;
		diameter = 0;
	}
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


void traverse(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	traverse(root->left);
	traverse(root->right);
	return;
}

// Gives the diameter of the tree in O(n) order.
// uses bottom up approach to do so. 

Pair diameter(Node *root){
	Pair c;
	if(root==NULL){
		return c;
	}
	Pair l = diameter(root->left);
	Pair r = diameter(root->right);
	c.height = 1 + max(l.height , r.height);
	c.diameter = max(l.height + r.height,max(l.diameter,r.diameter));
	return c;
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
	Pair p = diameter(root);
	cout<<"Diameter : "<<p.diameter<<endl;
	cout<<"Height : "<<p.height<<endl;
	return 0;
}



// TestCases.

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

// Output :  


// Diameter : 7
// Height : 5

// Diameter : 6
// Height : 4

