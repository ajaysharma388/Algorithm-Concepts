#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	int level;
	node*left;
	node*right;
	node(const int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}	
};


node* build(){
	int d;
	cin >> d;
	node*root = new node(d);
	root->level = 0;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node*cur = Q.front();
		Q.pop();
		int c1,c2;
		cin >> c1 >> c2;
		if(c1 != -1){
			cur->left = new node(c1);
			cur->left->level = cur->level + 1;
			Q.push(cur->left);
		}
		if(c2 != -1){
			cur->right = new node(c2);
			cur->right->level = cur->level + 1;
			Q.push(cur->right);
		}
	}
	return root;
}


void leftView(node*root){
	queue<node*> Q;
	Q.push(root);
	int cl = -1;
	while(!Q.empty()){
		node*cur = Q.front();
		Q.pop();
		if(cl < cur->level){
			cout << cur->data << " ";
			cl = cur->level;	
		} 
		if(cur->left){
			Q.push(cur->left);
		}
		if(cur->right){
			Q.push(cur->right);
		}
	}
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
	leftView(root);
	return 0;
}

// Sample Input :

// 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1

// 1 6 2 8 7 4 3 11 -1 9 -1 -1 5 -1 -1 -1 -1 10 -1 -1 -1 -1 -1

// Sample Output :

// 1 2 4

// 1 9 10 11 10