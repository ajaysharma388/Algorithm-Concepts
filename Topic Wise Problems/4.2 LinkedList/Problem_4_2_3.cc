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
	LinkedList(int s = 1, int e = 10)
	{
		this->head = createList(s, e);
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

	void insertAtHead(int data)
	{
		Node* cur = new Node(data);
		if (this->head == nullptr)
		{
			this->head = cur;
			this->tail = cur;
		} 
		else
		{
			cur->next = this->head;
			this->head = cur;
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
};

class Solution 
{
public:
	void connect(LinkedList *lst1, int n, LinkedList *lst2, int m, int pos)
	{
		cout << "Create This code\n";
	}

    void solve()
    {
    	int n, m;
    	cin >> n >> m;
    	int random = min(n-2, m);
       	LinkedList *lst1 = new LinkedList(3, n);
       	LinkedList *lst2 = new LinkedList(1, m);
       	lst1->print();
       	lst2->print();
       	cout << random << endl;
       	connect(lst1, n, lst2, m, random);
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
10

Sample Output:

TestCase #1 :
List : [ 1 2 3 4 5 6 7 8 9 10 11 ]
The Middle Node from Above Lst is 6
TestCase #2 :
List : [ 1 2 3 4 5 6 7 8 9 10 ]
The Middle Node from Above Lst is 5 6

*/