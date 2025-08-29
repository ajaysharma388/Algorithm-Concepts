#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class trienode
{
public:
	// left node represents 0.
	trienode*left;
	// right node represents 1.
	trienode*right;
};

void insert(int n,trienode*head){
	trienode*curr = head;
	// itarting from msb towards lsb.
	for(int i = 31; i >= 0; --i){
		int bit = (n>>i) & 1;
		if(bit == 0){
		// for zero as current bit we will check if left child is not
		// present then we will create the node that represents the left child.
			if(curr->left == NULL){
				curr->left = new trienode();
			}
		// moving to left child. 
			curr = curr->left;
		} else {
		// for one as current bit we will check if right child is not
		// present then we will create the node that represents the right child.
			if(curr->right == NULL){
				curr->right = new trienode();
			}
		// moving to right child. 
			curr = curr->right;
		}
	}
}

int findMaxXorPair(trienode*head,int*arr,int element){
	int max_xor = INT_MIN;
	trienode *curr = head;
	int value = element;
	int cur_xor = 0;
	for(int j = 31; j >= 0; --j){
		int bit = (value >> j) & 1;
		if(bit == 0){
			// if we can go for one then we will.
			if(curr->right != NULL){
				curr = curr->right;
				cur_xor += (int) pow(2,j);
			} else {
			// Otherwise we will compromise with zero. 
				curr = curr->left;
			}
		} else {
			// if we can go for zero then we will.
			if(curr->left != NULL){
				curr = curr->left;
				cur_xor += (int) pow(2,j);
			} else {
			// Otherwise we will compromise with zero.
				curr = curr->right;
			}
		}
	}
	if(max_xor < cur_xor){
		max_xor = cur_xor;
	}
	return max_xor;
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
	int *arr = new int[n]();
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}	
	trienode *head = new trienode();
	int result = INT_MIN;
	for(int i = 0; i < n; ++i){
		insert(arr[i],head);
		int x = findMaxXorPair(head,arr,arr[i]);
		result = max(result,x);
	} 
	cout << result << endl;
	delete []arr;
	return 0;
}

// Sample Input : 

// 6
// 3 10 5 25 8 2

// Sample Output : 

// 28