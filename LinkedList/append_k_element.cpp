#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

class node
{
public:
	int data;
	node* next;
	node(const int d){
		data = d;
		next = NULL;
	}
};

class LinkedList{
public:
	node* head;
	LinkedList(){
		head = NULL;
	}
	void push(const int data){
		node *ptr = new node(data);
		if(head==NULL) head = ptr;
		else{
			node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = ptr;
		}
		return;
	}
	int size(){
		int s = 0;
		node* h = head;
		while(h!=NULL){
			h = h->next;
			s++;
		}
		return s;
	}
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	node* kthFromBack(int k){
		node* b = head;
		for(int i=0;i<k;++i){
			b=b->next;
		}
		node* a = head;
		while(b!=NULL){
			a = a->next;
			b = b->next;
		}
		return a;  
	}

	node* rotateList(const int k){
		if(k==0) return head;
		node* f = kthFromBack(k);
		node* t = head;
		while(t->next!=f){
			t = t->next;
		}
		t->next = NULL;
		t = f;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next = head;
		return f;  
	}

	void append(const int k){
		if(k==0) return;
		int s = size();
		node* prev = NULL;
		node* current = head;
		for(int i=0;i<s-k;++i){
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		node* t = current;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next = head;
		head = current;
	}
};

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n;
	LinkedList *list = new LinkedList();
	for(int i=0;i<n;++i){
		cin >> k;
		(*list).push(k);
	}	
	cin >> k;
	k = k%n;
	(*list).append(k);
	(*list).print();
	return 0;
}



// Test Case 1

// Sample Input : 
// 7
// 1 2 2 4 8 5 6
// 7

// Sample Output : 
// 1 2 2 4 8 5 6 


// Test Case 2

// Sample Input : 
// 7
// 1 2 2 4 8 5 6
// 3

// Sample Output : 
// 8 5 6 1 2 2 4 


// Test Case 3

// Sample Input : 
// 7
// 1 2 2 4 8 5 6
// 1

// Sample Output : 
// 6 1 2 2 4 8 5  
