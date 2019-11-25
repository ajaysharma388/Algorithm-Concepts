#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


class Node{
public:
	int data,hd;
	Node* left;
	Node* right;
	Node(const int data){
		this->data = data;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

Node* buildTreeLevel(){
	queue<Node*> q;
	int data;
	cin >> data;
	Node*root = NULL;
	if(data!=-1){
		root = new Node(data);
		q.push(root);
	} 
	while(!q.empty()){
		Node* current = q.front();
		int c1,c2;
		cin >> c1 >> c2;
		if(c1!=-1){
			current->left = new Node(c1);
			q.push(current->left);
		}
		if(c2!=-1){
			current->right = new Node(c2);
			q.push(current->right);	
		}
		q.pop();
	}
	// returning the root node.
	return root;
}

void bottomTree(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node*current = q.front();
		if(current->left!=NULL && current->right!=NULL){
			q.push(current->left);
			q.push(current->right);
		}
		if(current->left==NULL || current->right==NULL){
			cout<<current->data<<" ";
		}
		q.pop();
	}
}


void printbottom(Node* root){
    if(root==NULL) return;
    int hd=0;
    root->hd=hd;
    queue<Node*> q;
    map<int,int> m;
    q.push(root);
    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        hd=temp->hd;
        m[hd]=temp->data;
        if(temp->left!=NULL){
            temp->left->hd=hd-1;
            q.push(temp->left);
        }

        if(temp->right!=NULL){
            temp->right->hd=hd+1;
            q.push(temp->right);
        }
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
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
	Node* root = buildTreeLevel();
	printbottom(root);
	return 0;
}