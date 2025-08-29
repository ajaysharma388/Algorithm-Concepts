#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node*right;
	node*left;
	node(const int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* buildTree(){
	int data;
	string lchild,rchild;
	cin >> data >> lchild;
	node* root = new node(data);
	if(lchild=="true"){
		root->left = buildTree();
	} 
	cin >> rchild;
	if(rchild=="true"){
		root->right = buildTree();
	}
	return root;	
}

void inorder(node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
	return;
}


bool checkIdentical(node*rootA,node*rootB){
	if(rootA==NULL and rootB==NULL) return true;
	if((rootA==NULL and rootB!=NULL) or 
		(rootA!=NULL and rootB==NULL)) return false;
	if(checkIdentical(rootA->left,rootB->left)
		and checkIdentical(rootA->right,rootB->right))
		return true;
	return false;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node*treeA = buildTree();
	node*treeB = buildTree();
	if(checkIdentical(treeA,treeB)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	return 0;
}