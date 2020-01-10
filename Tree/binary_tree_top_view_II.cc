#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

map<int,int> mp;

class node{
public:
	int data;
	int root_dist;
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
	root->root_dist = 0;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node*cur = Q.front();
		Q.pop();
		int c1,c2;
		cin >> c1 >> c2;
		if(c1 != -1){
			cur->left = new node(c1);
			cur->left->root_dist = cur->root_dist - 1;
			Q.push(cur->left);
		}
		if(c2 != -1){
			cur->right = new node(c2);
			cur->right->root_dist = cur->root_dist + 1;
			Q.push(cur->right);
		}
	}
	return root;
}


void inoder(node*root){
	if(root == NULL) return;
	if(mp.find(root->root_dist) == mp.end()){
		mp[root->root_dist] = root->data; 
	}
	inoder(root->left);
	inoder(root->right);
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
	inoder(root);
	for(auto node:mp){
		cout << node.second << " ";
	}
	return 0;
}

// Sample Input :

// 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1

// 1 6 2 8 7 4 3 11 -1 9 -1 -1 5 -1 -1 -1 -1 10 -1 -1 -1 -1 -1

// Sample Output :

// 4 1 2 3

// 11 8 6 1 2 3