#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data,d;
	node*left;
	node*right;
	node(const int data){
		this->data = data;
		d=0;
		left = right = NULL;
	}
};

node* buildTree(){
	int data,l,r;
	cin >> data;
	if(data==-1) return NULL;
	node* root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void setDistance(node*root,int cur=0){
	if(root==NULL) return;
	root->d = cur;
	int ld = cur-1;
	int rd = cur+1;
	setDistance(root->left,ld);
	setDistance(root->right,rd);
	return;
}

void inorder(node*root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

void vop(node*root,map<int,vector<int>>&v,int d=0){
	if(root==NULL) return;
	v[d].push_back(root->data);
	vop(root->left,v,d-1);
	vop(root->right,v,d+1);
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
	node* root = buildTree();
	setDistance(root);
	inorder(root);
	cout<<endl;
	map<int,vector<int>> v;
	vop(root,v);
	// for(auto it=v.begin();it!=v.end();++it){
	// 	vector<int> v = it->second;
	// 	for(int i=0;i<v.size();++i){
	// 		cout<<v[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(auto it=v.begin();it!=v.end();++it){
		for(int i=0;i<it->second.size();++i){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// Sample Input : 

// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 -1 7 -1 9 -1 -1

// Sample Output : 

// 4 2 5 8 1 6 3 7 9 
// 4 
// 2 
// 1 5 6 
// 8 3 
// 7 
// 9 