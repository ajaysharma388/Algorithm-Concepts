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
		this->left = NULL;
		this->right = NULL;
	}
};

class treeDetail{
public:
	bool isBst;
	int size;
	int max_value;
	int min_value;
};

int search(int*in,int s,int e,int data){
	int pos;
	for(int i=s;i<=e;++i){
		if(in[i] == data){
			pos = i;
			break;
		}
	}
	return pos;
}

int i = 0;

node* build(int*in,int*pre,int s,int e){
	if(s > e) return NULL;
	int idx = search(in,s,e,pre[i]);
	node*root = new node(in[idx]);
	i++;
	root->left = build(in,pre,s,idx-1);
	root->right = build(in,pre,idx+1,e);
	return root;
}


treeDetail largestBstInBT(node*root){
	treeDetail cur;
	// Base Case.
	if(root == NULL){
		cur.size = 0;
		cur.isBst = true;
		cur.min_value = INT_MAX;
		cur.max_value = INT_MIN;
		return cur;
	}
	// Left Tree Details.
	treeDetail leftDetail = largestBstInBT(root->left);
	// Right Tree Details.
 	treeDetail rightDetail = largestBstInBT(root->right);
 	// Condtions For Not BST.
	if(leftDetail.isBst == false or rightDetail.isBst == false or leftDetail.max_value > root->data 
		or rightDetail.min_value < root->data) {
		cur.isBst = false;
		cur.size = max(leftDetail.size,rightDetail.size);
		return cur;
	}
	// Cur Forms The BST.
	cur.isBst = true;
	cur.size = leftDetail.size + rightDetail.size + 1;
	cur.min_value = (root->left != NULL)? leftDetail.min_value : root->data ;
	cur.max_value = (root->right != NULL)? rightDetail.max_value : root->data ;
	return cur; 
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
	int *pre = new int[n]();
	int *in = new int[n]();
	for(int i = 0; i < n; ++i){
		cin >> pre[i];
	}	
	for(int i = 0; i < n; ++i){
		cin >> in[i];
	}
	node*root = build(in,pre,0,n-1);
	cout << largestBstInBT(root).size << endl;
	delete []in;
	delete []pre;
	return 0;
}

// Sample Input :

// 4
// 60 65 50 70
// 50 65 60 70

// Sample Output :

// 2