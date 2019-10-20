#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node{
	public:
		int data;
		Node *next;
		Node(const int d){
			data = d;
			next = NULL;
		}
};

void print(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void insert(Node* &head,const int data){
	if(head==NULL){
		head = new Node(data);
		return;
	}else{
		Node *temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new Node(data);
	}
}

void buildList(Node* &head){
	int data;
	cin >> data;
	while(data!=-1){
		insert(head,data);
		cin >> data;
	}
}

Node* merge(Node* a,Node* b){
	if(a==NULL) return b;
	if(b==NULL) return a;
	Node* c;
	if(a->data<=b->data){
		c=a;
		a=a->next;
	}else{
		c=b;
		b=b->next;
	}
	c->next=merge(a,b);
	return c;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	Node *head1 = NULL;
	Node *head2 = NULL;
	buildList(head1);
	buildList(head2);
	cout<<"ListA : ";
	print(head1);
	cout<<"ListB : ";
	print(head2);
	head1 = merge(head1,head2);
	cout<<"Merged List : ";
	print(head1);
	return 0;
}