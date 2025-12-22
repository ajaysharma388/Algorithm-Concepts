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
		for(int i = n-1; i > 0; --i)
		{
			insertAtTail(i);
		}
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

	bool isPalindromic()
	{
		int len = getLength();
		bool isOdd = false;
		if (len & 1)
		{
			isOdd = true;
		}
		stack<int> st;
		Node* ptr = this->head;
		int n = len/2;
		for(int i = 0; i < n; ++i)
		{
			st.push(ptr->data);
			ptr = ptr->next;
		}
		if (isOdd)
		{
			ptr = ptr->next;
		}
		while(!st.empty() and ptr)
		{
			if(st.top() == ptr->data)
			{
				st.pop();
				ptr = ptr->next;
				continue;
			}
			return false;
		}
		return true;
	}

	void ValidateIfPalindromic()
	{
		if (this->isPalindromic())
       	{
       		cout << "Yes the LinkedList is Palindromic" << endl;
       	}
       	else
       	{
       		cout << "The LinkedList is not Palindromic" << endl;
       	}
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
       	lst->ValidateIfPalindromic();
       	lst->insertAtTail(1);
       	lst->print();
       	lst->ValidateIfPalindromic();
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
List : [ 1 2 3 4 5 6 5 4 3 2 1 ]
Yes the LinkedList is Palindromic
List : [ 1 2 3 4 5 6 5 4 3 2 1 1 ]
The LinkedList is not Palindromic
*/