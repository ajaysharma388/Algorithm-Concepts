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

void insert(trienode*head,int n){
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

int subarray_with_max_xor(int*arr,int n){
	int curr_xor = 0;
	for(int i = 0; i < n; ++i){
		arr[i] = arr[i] ^ curr_xor;
		curr_xor = arr[i];
	}	
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << " -> " ;
	trienode *head = new trienode();
	int result = INT_MIN;
	for(int i = 0; i < n; ++i){
		insert(head,arr[i]);
		int x = findMaxXorPair(head,arr,arr[i]);
		result = max(result,x);
	} 
	return result;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n;
		cin >> n;
		int *arr = new int[n]();
		for(int i = 0; i < n; ++i){
			cin >> arr[i];
		}
		cout << subarray_with_max_xor(arr,n) << endl;
		delete []arr;
	}
	return 0;
}

// Sample Input :

// 5
// 4
// 1 2 3 4
// 6
// 8 1 2 12 7 6
// 6
// 3 10 5 25 8 2
// 2
// 4 6
// 13
// 2 5 3 7 7 7 0 5 3 8 2 6 4

// Sample Output :

// 1 3 0 4  -> 7
// 8 9 11 7 0 6  -> 15
// 3 9 12 21 29 31  -> 30
// 4 2  -> 6
// 2 7 4 3 4 3 3 6 5 13 15 9 13  -> 15