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

// we need to pass the array to this method and at the end
// this method will build the height balanced tree from the 
// elements of the array recursively in time O(n) & O(n) space.

Node* buildTreeFromArray(int *in,int s,int e){
	if(s>e) return NULL;
	int m = (s+e)/2;
	Node* root = new Node(in[m]);
	root->left = buildTreeFromArray(in,s,m-1);
	root->right = buildTreeFromArray(in,m+1,e);
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
	int *in = new int[n];
	for(int i=0;i<n;++i){
		cin >> in[i];
	}
	Node* root = buildTreeFromArray(in,0,n-1);
	levelOrder(root);
	return 0;
}


// Input : 

// 9
// 1 10 8 9 6 7 3 13 14 

// 9
// 8 10 1 3 6 9 7 14 13 

// Output : 

// 6 
// 10 3 
// 1 8 7 13 
// 9 14 

// 6 
// 10 7 
// 8 1 9 14 
// 3 13 


