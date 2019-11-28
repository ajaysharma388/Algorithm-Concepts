#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node*left;
	node*right;
	node(const int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node *createpreToIn(int *in ,int *pre,int s,int e){
	static int i=0;
	//base case
	if(s>e){
		return NULL;
	}
	node*root=new node(pre[i]);
	int index=0;
	for(int j=s;j<=e;j++){
		if(in[j]==pre[i]){
			index=j;
			break;
		}
	}
	i++;
	root->left=createpreToIn(in,pre,s,index-1);
	root->right=createpreToIn(in,pre,index+1,e);
	return root;
}


void print(node* root){
	if(root==NULL){
		return;
	}
	if(root->left!=NULL && root->right!=NULL){
		cout<< root->left->data <<" => "<<root->data<<" <= "<<root->right->data<<endl;
	}else if(root->left==NULL&&root->right!=NULL){
		cout<<"END => "<<root->data<<" <= "<<root->right->data<<endl;
	}else if(root->left!=NULL&&root->right==NULL){
		cout<<root->left->data<<" => "<<root->data<<" <= END"<<endl;
	}else{
		cout<<"END => "<<root->data<<" <= END"<<endl;
	}
	print(root->left);
	print(root->right);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin >> m;
	int *pre = new int[m];
	for(int i=0;i<m;++i){
		cin >> pre[i];
	}
	cin >> n;
	int *in = new int[n];
	for(int i=0;i<n;++i){
		cin >> in[i];
	}	
	node* root = createpreToIn(in,pre,0,n-1);
	print(root);
	return 0;
}