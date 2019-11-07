#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node
{
public:
	int data;
	Node* next;
	Node(const int d){
		data = d;
		next = NULL;
	}
	~Node();
};

Node* buildList(int n){
	int data;
	cin >> data;
	Node* curr = new Node(data);
	if(n==1) return curr;
	curr->next = buildList(n-1);
	return curr;
}

void traverse(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}


void ins(Node*&head){
	Node* pcur = NULL;
	Node* cur = head;
	while(cur!=NULL){
		Node* pre = cur;
		Node* p = cur;
		Node* min = p;
		Node* pmin = cur;
		while(p!=NULL){
			if(min->data > p->data){
				pmin = pre;
				min = p;
			}
			pre = p;
			p = p->next;
		}
		if(cur==head && cur!=min){
			Node*t = min->next;
			head = min;
			min->next = cur->next;
			pmin->next = cur;
			cur->next = t;
			cur = head;
		}
		if(cur!=min){
			Node*t = min->next;
			min->next = cur->next;
			pmin->next=cur;
			cur->next=t;
			pcur->next=min;
			cur = min;
		}
		pcur = cur;
		cur=cur->next;
	}
	return;
}

void insertAtTail(Node*&head,Node*ptr){
	if(head==NULL){
		head = ptr;
		ptr->next=NULL;
		return;
	}
	Node* t = head;
	while(t->next!=NULL){
		t = t->next;
	}
	t->next = ptr;
	ptr->next = NULL;
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
	Node* head = buildList(n);
	ins(head);
	traverse(head);
	return 0;
}