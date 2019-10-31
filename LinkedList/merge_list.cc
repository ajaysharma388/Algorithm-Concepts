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
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
};

node* merge(node* a,node* b){
	if(a==NULL) return b;
	if(b==NULL) return a;
	node* current;
	if(a->data<=b->data){
		current = a;
		a = a->next;
	}else{
		current = b;
		b = b->next;
	}
	current->next = merge(a,b);
	return current;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		LinkedList *lista = new LinkedList();
		LinkedList *listb = new LinkedList();
		int a,b;
		cin >> a;
		for(int i=0;i<a;++i){
			cin >> b;
			(*lista).push(b);
		}
		cin >> b;
		for(int i=0;i<b;++i){
			cin >> a;
			(*listb).push(a);
		}
		(*lista).head = merge((*lista).head,(*listb).head);
		(*lista).print();
		delete lista;
		delete listb;
	}
	return 0;
}