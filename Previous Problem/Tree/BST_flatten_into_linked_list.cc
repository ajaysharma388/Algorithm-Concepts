#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node
{
public:
	int data;
	Node*left;
	Node*right;
	Node(const int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

class LinkedList
{
public:
	Node* head;
	Node* tail;	
};

// Breadth first Search Or Level order Traversal 
// Time complexty is O(n).

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

// Method For Inserting the Node in the BST.

Node* insertInBST(Node*root,int data){
	if(root==NULL) return new Node(data);
	if(root->data>data)	root->left = insertInBST(root->left,data);
	else root->right = insertInBST(root->right,data);
	return root;
}

// This method uses above method to build the BST.

LinkedList flattenBST(Node*root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}
	// if No children.
	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	// if left child is available.
	if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = flattenBST(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	// if right child is available.
	if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = flattenBST(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	// if booth the child is available.
	LinkedList leftLL = flattenBST(root->left);
	LinkedList rightLL = flattenBST(root->right);
	leftLL.tail->right = root;
	root->right = rightLL.head;
	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}

Node* buildBST(){
	int data;
	Node*root = NULL;
	while(cin>>data && data!=-1){
		root = insertInBST(root,data);
	}
	return root;
}



int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node*root = buildBST();
	levelOrder(root);
	LinkedList LL = flattenBST(root);
	cout<<endl;
	Node* temp = LL.head;
	while(temp->right!=NULL){
		cout<<temp->data<<" --> ";
		temp=temp->right;
	}
	cout<<temp->data<<endl;
	return 0;
}


// Input : 

// 8 10 1 3 6 9 7 14 13 -1

// Output : 

// 8 
// 1 10 
// 3 9 14 
// 6 13 
// 7 

// 1 --> 3 --> 6 --> 7 --> 8 --> 9 --> 10 --> 13 --> 14
