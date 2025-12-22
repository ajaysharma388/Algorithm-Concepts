#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Node {
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {
private:
	int getLength()
	{
		int len = 0;			
		Node* ptr = this->head; 
		while(ptr)
		{
			ptr = ptr->next;
			len++;
		}
		return len;
	}

	Node* createList(int i, int n)
	{
		if(i == n)
		{
			Node* last = new Node(i);
			this->tail = last;
			return last;
		}
		Node* cur = new Node(i);
		cur->next = createList(i+1, n);
		return cur;
	}

	Node* head;
	Node* tail;

public:	
	LinkedList(int n)
	{
		this->head = createList(1, n);
	}

	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insertAtTail(int data)
	{
		Node* cur = new Node(data);
		if (this->head == nullptr)
		{
			this->head = cur;
			this->tail = cur;
		} 
		else
		{
			this->tail->next = cur;
			this->tail = cur;
		}
	}

	void insertAtHead(Node* ptr)
	{
		if (this->head == nullptr)
		{
			this->head = ptr;
			this->tail = ptr;
			this->head->next = nullptr;
		} 
		else
		{
			ptr->next = this->head;
			this->head = ptr;
		}
	}

	void print()
	{
		Node* cur = this->head;
		cout << "List : [ ";
		while(cur != this->tail->next)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "]" << endl;
	}

	void reverse()
	{
		Node* ptr = this->head;
		this->head = nullptr;
		this->tail = nullptr;

		while(ptr)
		{	
			Node* tmp = ptr->next;
			this->insertAtHead(ptr);
			ptr = tmp;
		}
		return;
	}
};

class Solution 
{
public:
    void solve()
    {
    	int n;
    	cin >> n;
       	LinkedList *lst = new LinkedList(n);
       	lst->print();
       	// lst->print();
       	lst->reverse();
       	lst->print();
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << t << " :\n";
        s->solve();        
    }
    return 0;
}

/*
Sample Input:

1
11

Sample Output:

TestCase #1 :
TestCase #1 :
List : [ 1 2 3 4 5 6 7 8 9 10 ]
List : [ 10 9 8 7 6 5 4 3 2 1 ]

*/