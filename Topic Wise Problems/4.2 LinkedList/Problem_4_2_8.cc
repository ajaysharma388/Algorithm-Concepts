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

	void print(Node* head)
	{
		Node* cur = head;
		cout << "List : [ ";
		while( cur )
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "]" << endl;
	}

	Node* reverse(Node* head)
	{
		Node* newHead = nullptr;
		Node* ptr = head;
		while(ptr)
		{
			Node* tmp = ptr->next;
			if(newHead == nullptr)
			{
				newHead = ptr;
				ptr->next = nullptr;
			}
			else
			{
				ptr->next = newHead;
				newHead = ptr;
			}
			ptr = tmp;
		}
		return newHead;
	}

	void reverseInKGroups(int k)
	{
		vector<pair<Node*, Node*>> groups;
		Node* tmp = this->head;
		int len = 0;
		while(tmp)
		{
			groups.push_back({tmp, nullptr});
			Node* prev = tmp;
			for(int i = 0; i < k; ++i)
			{
				prev = tmp;
				tmp = tmp->next;
				if(tmp == nullptr) break;
			}
			prev->next = nullptr;
			groups[len].second = prev;
			len++;
		}
		for(int i = 0; i < groups.size(); i+=2)
		{
			groups[i].second = reverse(groups[i].first);
			swap(groups[i].second, groups[i].first);
		}
		this->head = nullptr;
		for(auto nodes: groups)
		{
			if(this->head == nullptr)
			{
				this->head = nodes.first;
			}
			else
			{
				this->tail->next = nodes.first;
			}
			this->tail = nodes.second;
		}
	}
};

class Solution 
{
public:
    void solve()
    {
    	int n, k;
    	cin >> n >> k;
       	LinkedList *lst = new LinkedList(n);
       	lst->print();
       	lst->reverseInKGroups(k);
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

3
10 3
20 4
11 2

Sample Output:

TestCase #1 :
List : [ 1 2 3 4 5 6 7 8 9 10 ]
List : [ 3 2 1 4 5 6 9 8 7 10 ]
TestCase #2 :
List : [ 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
List : [ 4 3 2 1 5 6 7 8 12 11 10 9 13 14 15 16 20 19 18 17 ]
TestCase #3 :
List : [ 1 2 3 4 5 6 7 8 9 10 11 ]
List : [ 2 1 3 4 6 5 7 8 10 9 11 ]
*/