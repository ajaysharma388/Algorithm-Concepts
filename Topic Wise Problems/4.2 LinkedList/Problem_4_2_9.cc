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
	Node* random;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
		this->random = nullptr;
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
	// this is the function which creates the deep copy of the nodes.
	Node* cloneListWithRandom(Node* head) 
	{
        unordered_map<Node*, Node*> mp;
        Node* tmp = head;
        Node* newHead = NULL;
        Node* itr;
        while( tmp ) {
            if(newHead == NULL) 
            {
                newHead = new Node(tmp->data);
                itr = newHead;
                mp[tmp] = newHead;
            } else {
                itr->next = new Node(tmp->data);
                itr = itr->next;
                mp[tmp] = itr;
            }
            tmp = tmp->next;
        }
        tmp = head;
        itr = newHead;
        while(tmp) {
            if(tmp->random) {
                itr->random = mp[tmp->random];
            }
            itr = itr->next;
            tmp = tmp->next;
        }
        return newHead;
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
List : [ 1 2 3 4 5 6 ]
Loop Found in the LinkedList
Loop List : [ 1 2 3 4 5 6 3 4 5 6 3 4 5 6 3 ]

*/