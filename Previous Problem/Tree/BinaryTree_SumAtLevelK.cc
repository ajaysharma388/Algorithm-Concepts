#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


class Node{
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

void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

Node* buildTree(){
	int data,ch;
	cin >> data;
	Node *root = new Node(data);
	cin >> ch;
	if(ch!=0){
		root->left = buildTree();
		ch--;
	}
	if(ch!=0){
		root->right = buildTree();
		ch--;
	}
	return root;
}

int sumAtLevelK(Node*root,int k){
	if(root==NULL){
		return 0;
	}
	if(k==0 && root!=NULL){
		return root->data;
	}
	return sumAtLevelK(root->left,k-1)+sumAtLevelK(root->right,k-1);
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
	int k;
	cin >> k;
	int sum = sumAtLevelK(root,k);
	cout << sum << endl;
	return 0;
}

// Sample Input : 

// 1 2
// 2 2
// 3 0
// 4 0
// 5 2
// 6 0
// 7 0
// 2

// Sample Output : 

// 20