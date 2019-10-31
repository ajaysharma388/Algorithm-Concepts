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


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node *head;
	int data;
	cin >> data;
	while(data!=-1){
		push(head,data);
		cin >> data;
	}
	print(head);
	return 0;
}