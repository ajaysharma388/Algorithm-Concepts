#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

map<int,vector<int>> mp;

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
	vector<node*> treeNode;
	int data;
	while(scanf("%d",&data) != EOF){
    	if(data == -1){
			treeNode.push_back(NULL);
		} else {
            node*cur = new node(data);
			treeNode.push_back(cur);
		}
	}
	treeNode[0]->root_dist = 0;
	for(int i = 0; i < treeNode.size(); ++i){
		node*cur = treeNode[i];
		if(cur != NULL and treeNode[2*i+1]){
			cur->left = treeNode[2*i+1];
			treeNode[2*i+1]->root_dist = treeNode[i]->root_dist-1;
		}
		if(cur != NULL and treeNode[2*i+2]){
			cur->right = treeNode[2*i+2];
			treeNode[2*i+2]->root_dist = treeNode[i]->root_dist+1;
		}
		if(cur != NULL and treeNode[2*i+1] == NULL and treeNode[2*i+2] == NULL){
			cur->left = treeNode[2*i+1];
			cur->right = treeNode[2*i+2];
		}
	}
	return treeNode[0];
}


void processTree(node*root){
	if(root == NULL) return;
	mp[root->root_dist].push_back(root->data);
	processTree(root->left);
	processTree(root->right);
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
	processTree(root);
	for(auto node:mp){
		cout << node.second[0] << " ";	
	}
	return 0;
}

// Sample Input :

// 1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1

// Sample Output :

// 4 2 1 3