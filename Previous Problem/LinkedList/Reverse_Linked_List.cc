#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node* next;
	node(const int num){
		data = num;
		next = NULL;
	}
};

int ttlElement(node*);

class LinkedList{
public:
	int size;
	node* head;
	LinkedList(){
		size=0;
		head=NULL;
	} 
	void push(const int data){
		size++;
		node* ptr = new node(data);
		if(head==NULL){
			head = ptr;
			return;
		}else{
			node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}
	int getSize() const{
		return size;
	}
	void print(){
		node* temp = head;
		if(temp==NULL){
			cout<<"List is empty."<<endl;
		}else{
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	node* getKth(node* p,int k){
		node* ptr = p;
		while(k-- && ptr){
			ptr=ptr->next;
		}
		return ptr;
	}
	node* reverse(node* ptr){
		if(ptr==NULL || ptr->next==NULL) return ptr;
		node* tail = ptr;
		node* h = reverse(ptr->next);
		node* t = h; 
		while(t->next!=NULL){
			t=t->next;
		}
		t->next = tail;
		tail->next = NULL; 
		return h;
	}
	node* kreverse(node* ptr,int k){
		if(ttlElement(ptr)<=k){
			return reverse(ptr);
		}
		node* p = NULL;
		node* n = ptr;
		for(int i=0;i<k;++i){
			p = n;
			n = n->next;
		}
		p->next = NULL;
		ptr = reverse(ptr);
		p=ptr;
		while(p->next!=NULL){ 
			p=p->next;
		}
		p->next = kreverse(n,k);
	 	return ptr;
	}

};


int ttlElement(node* p){
	int i=0;
	while(p!=NULL){
		p=p->next;
		i++;
	}
	return i;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,data;
	cin >> n >> k;
	LinkedList *List = new LinkedList();
	for(int i=0;i<n;++i){
		cin >> data;
		(*List).push(data);
	}
	(*List).head = (*List).kreverse((*List).head,k);
	(*List).print();
	return 0;
}