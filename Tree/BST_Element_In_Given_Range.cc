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
	Node(const int data){
		this->data = data;
		left = right = NULL;
	}
};

Node* insertInBST(Node*root,const int data){
	if(root==NULL){
		return new Node(data);
	}
	if(root->data >= data){
		root->left = insertInBST(root->left,data);
	}else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}

Node* buildBst(){
	int n,data;
	Node* root = NULL;
	cin >> n;
	while(n--){
		cin >> data;
		root = insertInBST(root,data); 
	}
	return root; 
}

void preorder(Node*root){
	if(root==NULL){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	return;
}

void range(Node* root,int s,int e){
	if(root==NULL){
		return;
	}
	range(root->left,s,e);
	if(root->data>=s && root->data<=e){
		cout<<root->data<<" ";
	}
	range(root->right,s,e);
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
	int testCases;
	cin >> testCases;
	while(testCases--){
		int s,e;
		Node* root = buildBst();
		cin >> s >> e;
		cout<<"# Preorder : ";
		preorder(root);
		cout<<endl<<"# Nodes within range are : ";
		range(root,s,e);
	}
	return 0;
}