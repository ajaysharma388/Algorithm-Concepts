#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

class node
{
public:
	int data;
	node* next;
	node(const int d){
		data = d;
		next = NULL;
	}
};

void push(node *&head,const int data){
	node *ptr = new node(data);
	if(head==NULL) head = ptr;
	else{
		node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = ptr;
	}
	return;
}


int kthElement(node* p,int k){
	node* t = p;
	for(int i=1;i<k;++i){
		p = p->next;
	}
	while(p->next!=NULL){
		t = t->next;
		p = p->next;
	}
	return t->data;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node *head = NULL;
	int k;
	cin >> k;
	while(k!=-1){
		push(head,k);
		cin >> k;
	}	
	cin >> k;
	cout<<kthElement(head,k);
	return 0;
}