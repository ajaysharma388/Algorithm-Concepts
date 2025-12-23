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
		while(ptr != this->tail)
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

	void print_Loop()
	{
		int len = 3*getLength();
		Node* cur = this->head;
		cout << "Loop List : [ ";
		while(len)
		{
			cout << cur->data << " ";
			cur = cur->next;
			len -= 1;
		}
		cout << "]" << endl;
	}

	bool detectLoop()
	{
		Node* slow = this->head;
		Node* fast = this->head;
		while(fast and fast->next)
		{	
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) return true;
		}
		return false;
	}

	Node* getLoopMeetingPoint()
	{
		Node* slow = this->head;
		Node* fast = this->head;
		while(fast and fast->next)
		{	
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast) return slow;
		}
		return nullptr;
	}

	Node* getStartingOfCycle()
	{
		Node* ptr_1 = getLoopMeetingPoint();
		if ( ptr_1 == nullptr )
		{
			return nullptr;
		} 
		Node* ptr_2 = this->head;
		while(ptr_1 != ptr_2)
		{
			ptr_1 = ptr_1->next;
			ptr_2 = ptr_2->next;
		}
		return ptr_1;
	}

	void createLoop()
	{
		int pos = this->getLength()/2;
		Node* ptr = this->head;
		while(pos--)
		{
			ptr = ptr->next;
		}
		this->tail->next = ptr;
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
       	lst->createLoop();
       	if(lst->detectLoop())
       	{
       		cout << "Loop Found in the LinkedList" << endl;
       	}
       	else 
       	{
       		cout << "Loop is Not Present in LinkedList" << endl;
       	}
       	lst->print_Loop();
       	Node* loopStartingPt = lst->getStartingOfCycle();
       	if(loopStartingPt)
       	{
       		cout << "The Cycle Starts at Point : " << loopStartingPt->data << endl;
       	}
       	else
       	{
       		cout << "There is No Cycle in the list\n";
       	}
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
6

Sample Output:

TestCase #1 :
TestCase #1 :
List : [ 1 2 3 4 5 6 ]
Loop Found in the LinkedList
Loop List : [ 1 2 3 4 5 6 3 4 5 6 3 4 5 6 3 ]
The Cycle Starts at Point : 3

*/