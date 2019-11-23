#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node{
public:
	int data;
	Node*left;
	Node*right;
	Node(const int data){
		this->data = data;
		left = right = NULL;
	}
};

void INOrder(Node* root){
	if(root==NULL){
		return;
	}
	INOrder(root->left);
	cout<<root->data<<" ";
	INOrder(root->right);
	return; 
}



bool isIdentical(Node* rootA,Node* rootB){
	if(rootA==NULL && rootB==NULL) return true;
	if(rootA!=NULL && rootB!=NULL){
		return (
			rootA->data == rootB->data &&
			isIdentical(rootA->left,rootB->left) &&
			isIdentical(rootA->right,rootB->right)
		);
	}
	return false;
}


bool isIdenticalIsPossible(Node* rootA,Node* rootB){
	if(rootA==NULL and rootB==NULL) return true;
	if(rootA!=NULL and rootB!=NULL){
		return isIdentical(rootA->left,rootB->left) 
		and isIdentical(rootA->right,rootB->right);
	}
	return false;
}

Node* buildTree(){
	int data;
	cin >> data;
	Node* root = new Node(data);
	string fl;
	cin>>fl;
	if(fl=="true"){
		root->left = buildTree();
	}
	cin>>fl;
	if(fl=="true"){
		root->right = buildTree();
	}
	return root;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	Node* rootA = buildTree();
	Node* rootB = buildTree();
	if(isIdentical(rootA,rootB)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}