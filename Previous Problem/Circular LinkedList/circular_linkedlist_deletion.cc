#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// Data Structure that will represents the node 
// on the computer's memory.

class Node{
	public:
		int data;
		Node *next;
		Node(const int d){
			data = d;
			next = NULL;
		}
};

// This method simply push the function into the list
// can also able to push into empty Circular Linked List.

void push(Node *&head,const int data){
	Node *n = new Node(data);
	Node *temp = head;
	n->next = head;
	if(head!=NULL){
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next = n;
	}else{
		n->next = n;
	}
	head = n;
}

// simply traverse the Circular Linked List
// and print the data part of it.

void print(Node *&head){
	Node *temp = head;
	while(temp->next!=head){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}



// this method will delete the node from the
// list if the data part of the node is same 
// as data passed by user during it's call to delete.

void deleteFromList(Node *&head,const int data){
	Node* p = NULL;
	Node* c = head;
	while(c->next!=head){
		if(data==c->data){
			if(p==NULL){
				p = head;
				head = c->next;
				Node* temp=head;
				while(temp->next!=p){
					temp=temp->next;
				}
				temp->next = head;
				delete c;	
			}else{
				p->next = c->next;
				delete c;	
			}	 
			return;
		}
		p = c;
		c = c->next;
	}
	if(c->data==data){
		p->next = head;
		delete c;
		return;
	}
}


// this method will return the address of 
// the node that contains the data equal to
// what user have passed during it's call.
// and if data is not present it will simply return 
// NULL back to the point from where it is being called.

Node* getNode(Node* head,const int data){
	Node* current = head;
	while(current->next!=head){
		if(current->data==data){
			return current;
		}
		current = current->next;
	}
	return (current->data==data)? current : NULL ;
}

// another way to do deletion deom the linked list.

void deleteNode(Node *&head,const int data){
	Node* del = getNode(head,data);
	if(del==NULL){
		cout<<"Node "<<data<<" is not available in the list"<<endl;
		return;
	}
	if(del == head){
		head = del->next;
	}
	Node* c = head;
	while(c->next!=del){
		c=c->next;
	}
	c->next = del->next;
	delete del;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *head=NULL;
    int data;
    cin >> data;  // input : 5 4 3 2 1 0 -1
    while(data!=-1){
    	push(head,data);
    	cin >> data;
    }
    print(head); // output : 0 -> 1 -> 2 -> 3 -> 4 -> 5
    deleteNode(head,5); 
    print(head); // output : 0 -> 1 -> 2 -> 3 -> 4
	return 0;
}