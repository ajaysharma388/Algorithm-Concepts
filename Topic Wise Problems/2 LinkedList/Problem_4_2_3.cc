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
	Node* iterator;

public:	
	LinkedList(int s = 1, int e = 10)
	{
		this->head = createList(s, e);
		this->iterator = this->head;
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

	Node* getTail()
	{
		return this->tail;
	}

	void setTail(Node* newTail)
	{
		this->tail = newTail;
	}

	Node* getKthNodeFromStart(int k)
	{
		Node* ptr = this->head;
		while(k and ptr)
		{
			k -= 1;
			ptr = ptr->next;
		}
		return ptr;
	}

	bool hasNext()
	{
		if (this->iterator == nullptr)
			return false;
		return true;
	}

	Node* getNext()
	{
		this->iterator = this->iterator->next;
		return this->iterator;
	}

	Node* initIterator()
	{
		return this->iterator = this->head;
	}
};

class Solution 
{
public:

	Node* findIntersection(LinkedList *lst1, LinkedList *lst2)
	{
		unordered_set<Node*> mp;
		int n = lst1->getLength();
		int m = lst2->getLength();
		if (m < n)
		{
			swap(lst1, lst2);
		}
		Node* itr = lst1->initIterator();
		while(lst1->hasNext())
		{
			mp.insert(itr);
			itr = lst1->getNext();
		} 

		itr = lst2->initIterator();
		while(lst2->hasNext())
		{
			if (mp.find(itr) != mp.end())
				return itr;
			mp.insert(itr);
			itr = lst2->getNext();
		} 
		return nullptr;
	}


	void RemoveIntersection(LinkedList *lst1, LinkedList *lst2)
	{
		unordered_set<Node*> mp;
		int n = lst1->getLength();
		int m = lst2->getLength();
		if (m < n)
		{
			swap(lst1, lst2);
		}
		Node* itr = lst1->initIterator();
		while(lst1->hasNext())
		{
			mp.insert(itr);
			itr = lst1->getNext();
		} 
		Node* pre = nullptr;
		itr = lst2->initIterator();
		while(lst2->hasNext())
		{
			if (mp.find(itr) != mp.end())
			{
				pre->next = nullptr;
				return;
			}
			mp.insert(itr);
			pre = itr;
			itr = lst2->getNext();
		} 
	}

	void connect(LinkedList* lst1, int n, LinkedList* lst2, int m, int pos) {
	    Node* ptr1 = lst1->getKthNodeFromStart(pos);
	    Node* ptr2 = lst2->getTail();

	    if (!ptr1 or !ptr2) 
	    {
	        cout << "Invalid connection attempt" << endl;
	        return;
	    }
	    ptr2->next = ptr1;
	    lst2->setTail(lst1->getTail());
	}

    void solve()
    {
    	int n, m;
	    cin >> n >> m;
	    if (n <= 2 || m <= 0) {
	        cout << "Invalid sizes" << endl;
	        return;
	    }
	    int random = rand() % (n - 2);
	    LinkedList* lst1 = new LinkedList(3, n);
	    LinkedList* lst2 = new LinkedList(1, m);
	    connect(lst1, n, lst2, m, random);
	    // Now we will try to find the intersection of two list.
	    Node* intersect = findIntersection(lst1, lst2);
	    if ( intersect == nullptr )
	    	return;
	    cout << "The two List are intersecting at Point " << intersect->data << endl;
	    lst1->print();
	    lst2->print();

	    cout << "Removing the Intersection in List" << endl;
	    RemoveIntersection(lst1, lst2);
	    lst1->print();
	    lst2->print();
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
9

Sample Output:

TestCase #1 :
The two List are intersecting at Point 7
List : [ 3 4 5 6 7 8 9 10 11 ]
List : [ 1 2 3 4 5 6 7 8 9 7 8 9 10 11 ]
Removing the Intersection in List
List : [ 3 4 5 6 7 8 9 10 11 ]
List : [ 1 2 3 4 5 6 7 8 9 ]

*/