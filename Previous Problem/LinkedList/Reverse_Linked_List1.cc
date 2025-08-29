#include<iostream>
using namespace std;
class Node 
{
 public:
	 int data; 
	 Node* next; 
	 Node(int d)
	 {
	 	data = d;
	 	next = NULL;
	 }
};
Node* Reverse(Node* head, int k)
{
	int count = 0;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	while(current!=NULL && count<k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next!=NULL){
		head->next = Reverse(next,k);
	}
	return prev;
}
void Insert(Node *&head, int data)
{
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	Node* nn = new Node(data);
	temp->next = nn;
	return;
}
void print(Node* head)
{
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
        Node* head = NULL;
	    int n,k,data;
	    cin>>n;
	    for(int i=0;i<n;i++){
		    cin>>data;
		    Insert(head,data);
	    }
	    cin>>k;
	    head = Reverse(head,k);
	    print(head);
        cout<<endl;
    }
	    return 0;
}

// Sample Test Cases: 
// Input :
// 8
// 1 2 3 4 5 6 7 8
// 3
// Output : 3 2 1 6 5 4 8 7 

// Input :
// 9
// 1 2 3 4 5 6 7 8 9
// 3
// Output : 3 2 1 6 5 4 9 8 7 

// Input : 
// 3
// 1 2 3
// 2
// Output : 2 1 3