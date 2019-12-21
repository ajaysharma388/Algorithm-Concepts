#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node{
public:
	int data;
	Node*next;
	Node(const int d){ 
		data = d;
		next = NULL;
	}
};

Node* createList(){
	static map<int,Node*> mp;
	int data;
	cin >> data;
	Node* root = NULL;
	if(mp.count(data)==0){
		root = new Node(data);
		mp[data] = root;
		root->next = createList();
	}else{
		return mp[data];
	}
	return root;
}

void removeCycle(Node*root,Node*loop_node){
	Node*ptra = loop_node->next;
	int k=1;
	while(ptra!=loop_node){
		ptra=ptra->next;
		k++;
	}
	ptra = root;
	Node*ptrb = root;
	while(k--){
		ptrb = ptrb->next;
	}
	while(ptra!=ptrb){
		ptra = ptra->next;
		ptrb = ptrb->next;
	}
	while(ptrb->next!=ptra){
		ptrb = ptrb->next;
	}
	ptrb->next=NULL;
}

bool detectCycle(Node*root){
	Node*slow = root;
	Node*fast = root;
	while(fast!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow){
			removeCycle(root,slow);
			return true;
		}
	}
	return false;
}

void printList(Node*root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->next;
	}
	return;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* head = createList();
	if(detectCycle(head)){
		printList(head);
	}
	return 0;
}