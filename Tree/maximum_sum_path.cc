#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int maxPath = INT_MIN;

class node{
public:
	int data;
	node*left;
	node*right;
	node(const int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* build(){
	int data;
	cin >> data;
	if(data == -1) return NULL;
	node*root = new node(data);
	root->left = build();
	root->right = build();
	return root;
}

int max_path_sum(node*root){
	if(root == NULL) return 0;
	int leftMax = max_path_sum(root->left);
	int rightMax = max_path_sum(root->right);
	// ignore if the sum till now is -ve;
	leftMax = max(0 , leftMax);
	rightMax = max(0 , rightMax);
	// setting up the maxpath. 
	maxPath = max(maxPath , leftMax + rightMax + root->data);
	// returning the single path.
	return max(leftMax , rightMax) + root->data;
}

void inorder(node*root){
	if(root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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
	node*root = build();
	max_path_sum(root);
	cout << "The Maximum Sum Of Path : " << maxPath << endl;
	return 0;
}

// Sample Input : 

// 8 6 2 3 -1 -1 -1 6 -11 -1 -1 -7 -1 -1 10 -1 -12 -1 11 -1 -1

// Sample Output :

// The Maximum Sum Of Path : 30