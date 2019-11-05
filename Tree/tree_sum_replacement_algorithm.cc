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

// replaces the sum of the children from it's current value
// uses postorder traversal or bottom up approach and solves 
// the problem in O(n) time in the worst case.

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

// Input : 

// 3 4 5 6 -1 -1 7 -1 -1 8 -1 -1 9 -1 10 11 -1 -1 12 13 -1 -1 14 -1 -1


// Output : 

// 99 
// 26 60 
// 13 8 50 
// 6 7 11 27 
// 13 14 