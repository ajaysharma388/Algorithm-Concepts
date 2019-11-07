#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node
{
public:
	int data;
	Node*left;
	Node*right;
	Node(const int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

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

// Method For Inserting the Node in the BST.

Node* insertInBST(Node*root,int data){
	if(root==NULL) return new Node(data);
	if(root->data>data)	root->left = insertInBST(root->left,data);
	else root->right = insertInBST(root->right,data);
	return root;
}

// This method uses above method to build the BST.

Node* buildBST(){
	int data;
	Node*root = NULL;
	while(cin>>data && data!=-1){
		root = insertInBST(root,data);
	}
	return root;
}

// check whether the Tree is BST or Not 
// Uses top-down approach.

bool isBST(Node*root,int minV = INT_MIN,int maxV = INT_MAX){
	if(root==NULL) return true;
	return (root->data < maxV && root->data >= minV) 
		? isBST(root->left,minV,root->data)
		 && isBST(root->right,root->data,maxV) : false ;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node*root = buildBST();
	if(isBST(root)){
		cout<<"Yes It is BST."<<endl;	
	}else{
		cout<<"No It is not BST."<<endl;	
	} 
	levelOrder(root);
	return 0;
}