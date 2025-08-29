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

void inorder(Node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

void preorder(Node *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

// we need to pass the inorder and pre order traversals
// this method will return the tree with those traversals.
// recursively in time O(n) && takes O(n) space as well.

Node* buildTreeFromTraversal(int *in,int *pre,int s,int e){
	if(s>e) return NULL;
	static int i = 0;
	Node* root = new Node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;++j){
		if(in[j]==pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = buildTreeFromTraversal(in,pre,s,index-1);
	root->right = buildTreeFromTraversal(in,pre,index+1,e);
	return root;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *pre = new int[n];
	int *in = new int[n];
	for(int i=0;i<n;++i){
		cin >> in[i];
	}
	for(int i=0;i<n;++i){
		cin >> pre[i];
	}
	Node* root = buildTreeFromTraversal(in,pre,0,n-1);
	levelOrder(root);
	return 0;
}


// Input : 

// 9
// 1 10 8 9 6 7 3 13 14 
// 8 10 1 3 6 9 7 14 13 

// Output : 

// 8 
// 10 3 
// 1 6 14 
// 9 7 13 