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
		left = NULL;
		right = NULL;
	}
};

Node* buildTree(){
	int data;
	cin >> data;
	string left,right;
	Node* root = new Node(data);
	cin >> left;
	if(left=="true"){
		root->left = buildTree();
	}
	cin >> right;
	if(right=="true"){
		root->right = buildTree();
	}
	return root;
}

void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}


int height(Node* root){
	if(root==NULL){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}

bool isbalanceBST(Node*root){
	if(root==NULL) return true;
	if(root->right==NULL && root->left==NULL){
		return true;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh)>1) return false; 
	return isbalanceBST(root->left) && isbalanceBST(root->right);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = buildTree();
	if(isbalanceBST(root)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	inorder(root);
	return 0;
}