#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Node{
public:
	int data;
	Node* next;
	Node(const int d){
		data = d;
		next = NULL;
	}
};

Node* insertAtTail(Node* head,const int data){
	Node* ptr = new Node(data);
	if(head==NULL){
		return ptr;
	}
	Node* t = head;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = ptr;
	return head;
}

Node* build(int length){
	Node* head = NULL;
	int data;
	while(cin>>data && length--){
		head = insertAtTail(head,data);
	}
	return head;
}

void print(Node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

bool compare(Node* ListA,Node* ListB){
	while(ListA!=NULL && ListB!=NULL){
		if(ListA->data != ListB->data){
			return false;
		}
		ListA = ListA->next;
		ListB = ListB->next;
	}
	return true;
}

Node* reverse(Node*root){
	Node* t = root->next;
	root->next = NULL;
	while(t!=NULL){
		Node* temp = t->next;
		t->next = root;
		root = t;
		t = temp;
	}
	return root;
}


bool breakList(Node* root,int length){
	int i = 0;
	Node* t = root;
	while(i<length/2){
		t = t->next;
		i++;
	}
	Node* root1 = reverse(t->next);
	t->next = NULL;
	return compare(root,root1);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int length;
	cin >> length;
	Node* head = build(length);
	if(breakList(head,length)){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}	
	return 0;
}