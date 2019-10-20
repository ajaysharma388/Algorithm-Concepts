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

void reverseRecursive(Node* &current,Node* prev,Node* next){
	if(current==NULL){
		current = prev;
		return;
	}
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	reverseRecursive(current,prev,next);
}

Node* reverse(Node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* sm = reverse(head->next);
	Node* current = head;
	current->next->next = current;
	current->next = NULL;
	return sm;
}

void reverseIterative(Node* &head){
	Node *prev,*next;
	prev = NULL;
	next = NULL;
	while(head!=NULL){
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	Node *head = NULL;
	buildList(head);
	print(head);
	head = reverse(head);
	print(head);
	return 0;
}