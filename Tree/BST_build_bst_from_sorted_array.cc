#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(const int d){
		data = d;
		left = right = NULL;
	}
};

void preOrder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}


Node* buildBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}
	int m = (s+e)/2;
	Node* root = new Node(a[m]);
	root->left = buildBST(a,s,m-1);
	root->right = buildBST(a,m+1,e);
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
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		Node* root = buildBST(a,0,n-1);
		preOrder(root);
		cout<<endl;
	} 
	return 0;
}