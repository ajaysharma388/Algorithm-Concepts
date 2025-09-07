#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    if(read) {
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

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int _value)
    {
        this->val = _value;
        this->next = nullptr;
    }
};

void print(ListNode* head)
{
    cout << "List: ";
    while(head != nullptr)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createListOfSize()
{
    int size, val;
    cin >> size;
    ListNode* head = nullptr;
    ListNode* ptr;
    for(int i = 0; i < size; ++i)
    {
        cin >> val;
        if( head == nullptr )
        {
            head = new ListNode(val);
            ptr = head;
        }
        else
        {
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
    }
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> Q;
    ListNode* newList = nullptr;
    ListNode* ptr;
    for(int i = 0; i < lists.size(); ++i)
    {
        Q.push({lists[i]->val, lists[i]});
    }
    while(!Q.empty())
    {
        auto cur = Q.top();
        Q.pop();
        if(cur.second->next)
        {
            Q.push({cur.second->next->val, cur.second->next});
        }
        
        if(newList == nullptr)
        {
            newList = cur.second;
            ptr = newList;
        }
        else
        {
            ptr->next = cur.second;
            ptr = ptr->next;
        }
    }
    return newList;
}

int main() 
{
    fastio(true);
    int cnt;
    cin >> cnt;
    vector<ListNode*> lists;
    while (cnt--) 
    {
        ListNode* head = createListOfSize();
        lists.push_back(head);
    }    
    
    print(mergeKLists(lists)); 
    return 0;
}