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
	}
	~Node();
};

class HBPair{
public:
	int height;
	bool balanced;
};

Node* buildTree(){
	int data;
	cin >> data;
	if(data==-1){
		return NULL;
	}
	Node *cur = new Node(data);
	cur->left = buildTree();
	cur->right = buildTree();
	return cur;
}

void traverse(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	traverse(root->left);
	traverse(root->right);
	return;
}

// checks the tree whether it is height balanced or not.
// uses the bottom up approach and solves the problem in O(n) time.


HBPair isHeightBalanced(Node* root){
	HBPair curr;
	if(root==NULL){
		curr.height = 0;
		curr.balanced = true;
		return curr;
	}
	HBPair left = isHeightBalanced(root->left);
	HBPair right = isHeightBalanced(root->right);
	curr.height = max(left.height , right.height) + 1;
	curr.balanced = (abs(left.height - right.height) <= 1 && left.balanced && right.balanced)
		? true : false;
	return curr;
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
	traverse(root);
	if(isHeightBalanced(root).balanced){
		cout<<endl<<"Tree is Balanced."<<endl;
	}else{
		cout<<endl<<"Tree is Not Balanced."<<endl;
	}
	return 0;
}