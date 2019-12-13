// Question : cycle detection algorithm using hasing.
// This implementation has O(N) time complexity and O(N)
// Space complexity.

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node* next;
	node(const int data){
		this->data = data;
		next = NULL; 
	}
};

node* buildList(){
	node* ptr = NULL;
	int data;
	cin >> data;
	if(data!=-1){
		ptr = new node(data);
		ptr->next = buildList();
	}
	return ptr;
}

void print(node*root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->next;
	}
	cout<<endl;
}

void createCycle(node*&root){
	node* temp = root;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = root->next->next->next;
}

bool detectCycle(node*root){
	unordered_map<node*,bool> table;
	while(root!=NULL){
		if(table[root]==true){
			return true;
		}
		table[root] = true;
		root = root->next;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* head = buildList();	
	createCycle(head);
	if(detectCycle(head)){
		cout<<"Cycle Detected."<<endl;
	}else{
		cout<<"Cycle Not Detected."<<endl;
	}
	return 0;
}

// Sample Input : 

// 1 2 3 4 5 6 7 -1

// Sample Output : 

// Cycle Detected