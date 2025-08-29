#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node*right;
	node*left;
	int level;
	node(const int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* build(){
	int d;
	cin >> d;
	queue<node*> Q;
	node*root = new node(d);
	root->level = 0;
	Q.push(root);
	while(!Q.empty()){
		int c1,c2;
		cin >> c1 >> c2;
		node*cur = Q.front();
		Q.pop();
		if(c1 != -1){
			cur->left = new node(c1);
			cur->left->level = cur->level+1;
			Q.push(cur->left); 
		}
		if(c2 != -1){
			cur->right = new node(c2);
			cur->right->level = cur->level+1;
			Q.push(cur->right);
		}
	}
	return root;
}


void traversebyLevel(node*root){
	queue<node*> Q;
	vector<node*> res;
	Q.push(root);
	while(!Q.empty()){
		node*temp = Q.front();
		res.push_back(temp);
		Q.pop();
		if(temp->left){
			Q.push(temp->left);
		}		
		if(temp->right){
			Q.push(temp->right);
		}
	}
	node*pre = NULL;
	node*cur = NULL;
	for(int i = 0; i < res.size(); ++i){
		cur = res[i];
		if(pre and pre->level != cur->level){
			cout << pre->data << " ";
		}
		pre = cur;
	}
	cout << pre->data;
	return;		
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
	traversebyLevel(root);
	return 0;
}

// Sample Input :

// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1

// Sample Output :

// 1 3 6