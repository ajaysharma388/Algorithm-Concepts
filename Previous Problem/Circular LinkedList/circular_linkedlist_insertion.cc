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
	return 0;
}