#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


class Node{
public:
	int data;
	Node*left;
	Node*right;
	Node(const int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* build(int* arr,int s,int e){
	if(s>e){
		return NULL;
	}
	int m = (s+e)/2;
	Node*root = new Node(arr[m]);
	root->left = build(arr,s,m-1);
	root->right = build(arr,m+1,e);
	return root;
}

void preorder(Node*root){
	if(root==NULL){
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	return;
}

void replacenode(Node* root,int *sum)
{
	if(root==NULL)
	{
		return;
	}
	replacenode(root->right,sum);
	*sum=*sum + root->data;
	root->data=*sum;
	replacenode(root->left,sum);
}
void replacesum(Node* root)
{
	int sum=0;
	replacenode(root,&sum);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	Node* root = build(a,0,n-1);
	replacesum(root);
	preorder(root);
	return 0;
}