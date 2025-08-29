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

int getHeight(Node* root){
	if(root==NULL) return 0;
	int ls,rs;
	ls = getHeight(root->left);
	rs = getHeight(root->right);
	return max(ls,rs)+1;
}

void kthlevel(Node* root,int k){
	if(root==NULL) return;
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	kthlevel(root->left,k-1);
	kthlevel(root->right,k-1);
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
	root = build();
	int h = getHeight(root);
	int n,l;
	cin >> n;
	l = (n%h)? n%h : n%h+1;
	kthlevel(root,l);
	return 0;
}



// TestCases.

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1
// 3

// 8 10 1 -1 -1 -1 3 6 9 -1 -1 7 -1 -1 14 13 -1 -1
// 3

// Output :  

// 9 7 13 15 
// 10 3
