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

int replaceSum(Node* &r){
	if(r==NULL) return 0;
	if(r->left==NULL && r->right==NULL) return r->data;
	int temp = r->data;
	r->data = replaceSum(r->left) + replaceSum(r->right); 
	return temp+r->data;
}

void levelOrder(Node* root){
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		Node* f = Q.front();
		if(f==NULL){
			Q.pop();
			cout<<endl;
			if(!Q.empty()){ Q.push(NULL); }
		}else{
			cout<<f->data<<" ";
			if(f->left){
				Q.push(f->left);
			}
			if(f->right){
				Q.push(f->right);
			}
			Q.pop();
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
	replaceSum(root);	
	levelOrder(root);
	return 0;
}


// 3 
// 4 9 
// 5 8 10 
// 6 7 11 12 
// 13 14 