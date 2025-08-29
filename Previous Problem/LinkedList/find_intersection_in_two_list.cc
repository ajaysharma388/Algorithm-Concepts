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
	cout<<endl;
}

int length(Node *head){
	int l = 0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}

// this is the naive approach to find the 
// intersection between two list.
// the time complexity of this method will
// be O(m*n) where,m is the length of list1.
// and n be the length of list2.

Node* findIntersection(Node *p,Node *qtr){
	Node* q;
	while(p!=NULL){
		q = qtr;
		while(q!=NULL){
			if(q->data==p->data){
				return q;
			}
			q = q->next;
		}
		p = p->next;
	}
	return NULL;
}

Node* intersection(Node *p,int m,Node *q,int n){
	int d = abs(m-n);
	if(m>n){
		for(int i=1;i<=d;++i){
			p = p->next;
		}
	}else{
		for(int i=1;i<=d;++i){
			q = q->next;
		}
	}
	while(p!=NULL && q!=NULL){
		if(p->data==q->data) return p;
		p = p->next;
		q = q->next;
	}
	return NULL;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node *list1 = NULL;
	Node *list2 = NULL;
	int m,n,data;
	cin >> m;
	for(int i=0;i<m;++i){
		cin >> data;
		push(list1,data);
	}
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> data;
		push(list2,data);
	}
	Node* ptr = intersection(list1,m,list2,n);
	if(ptr!=NULL)cout<<ptr->data<<endl;
	else cout<<"-1"<<endl;
	return 0;
}