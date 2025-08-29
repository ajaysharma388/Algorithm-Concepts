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
	Node(const int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree(){
	int data;
	cin >> data;
	string left,right;
	Node* root = new Node(data);
	cin >> left;
	if(left=="true"){
		root->left = buildTree();
	}
	cin >> right;
	if(right=="true"){
		root->right = buildTree();
	}
	return root;
}

int height(Node*root){
	if(root==NULL){
		return 0;
	}
	return max(height(root->left),height(root->right))+1;
}

void getKthLevel(Node*root,int k,vector<Node*> &nodes){
	if(root==NULL){
		return;
	}
	if(k==1){
		// cout<<root->data<<" ";
		nodes.push_back(root);
		return;
	}
	getKthLevel(root->left,k-1,nodes);
	getKthLevel(root->right,k-1,nodes);
}


void zigZaglevelorder(Node* root){
	int h = height(root);
	for(int i=1;i<=h;++i){
		vector<Node*> vec;
		getKthLevel(root,i,vec);
		if(i&1){
			for(int k=0;k<vec.size();++k){
				cout << vec[k]->data << " ";
			}
		}else{
			for(int k=vec.size()-1;k>=0;--k){
				cout << vec[k]->data << " ";
			}
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
	Node* root = buildTree();
	zigZaglevelorder(root);
	return 0;
}