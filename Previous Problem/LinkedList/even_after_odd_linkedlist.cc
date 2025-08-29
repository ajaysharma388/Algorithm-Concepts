#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node
{
public:
	int data;
	Node *next;
	Node(const int d){
		data = d;
		next = NULL;
	}
};

void push(Node *&head,int data){
	Node *ptr = new Node(data);
	if(head == NULL) head = ptr;
	else{
		Node *t = head;
		while(t->next != NULL){
			t = t->next;
		}
		t->next = ptr;
	}
}

void print(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void pushNode(Node *&head,Node *&tail,Node *node){
	if(head==NULL){
		head = node;
		tail = node;
	}else{
		Node *t = head;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next = node;
		tail = t->next;
	}
	node->next = NULL;
}

Node* evenOdd(Node *head){
	Node* o = NULL;
	Node* ot = NULL;
	Node* e = NULL;
	Node* et = NULL;
	while(head!=NULL){
		Node *h = head;
		head = head->next;
		if(h->data&1){
			pushNode(o,ot,h);
		}else{
			pushNode(e,et,h);
		}
	}
	if(o==NULL) return e;
	if(e==NULL) return o;
	ot->next = e;
	return o;
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
	Node *head = NULL;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		push(head,data);
	}
	head = evenOdd(head);
	print(head);
	return 0;
}