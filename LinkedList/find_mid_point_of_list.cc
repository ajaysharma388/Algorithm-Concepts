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


Node* midPoint(Node* head){
	if(head->next==NULL || head==NULL) return head;
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=NULL && fast->next!=NULL ){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
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
	Node* mid = midPoint(head);
	cout<<mid->data<<endl;
	return 0;
}