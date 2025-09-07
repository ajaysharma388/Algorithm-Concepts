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
    while(head != nullptr)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createListOfSize(int cnt, int k)
{
    ListNode* head = nullptr;
    ListNode* ptr;
    for(int i = 0; i < cnt; ++i)
    {
        int val;
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

ListNode* reverseList(ListNode* head)
{
    ListNode* newHead = nullptr;
    ListNode* next;
    ListNode* cur = head;
    while( cur )
    {
        next = cur->next;
        if(newHead == nullptr)
        {
            newHead = cur;
            cur->next = nullptr;  
        } 
        else
        {
            cur->next = newHead;
            newHead = cur;
        }
        cur = next;  
    }
    return newHead;
}

ListNode* connectAllList(vector<ListNode*> lists, int len)
{
    ListNode* head = nullptr;
    ListNode* ptr;
    ListNode* prev;
    for(int i = 0; i < len; ++i)
    {
        ptr = lists[i];
        while(ptr)
        {
            if(head == nullptr)
            {
                head = ptr;
            }
            else
            {
                prev->next = ptr;    
            }    
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if(lists.size() > len) prev->next = lists[len];
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1) return head;
    vector<ListNode*> lists;
    ListNode* cur = head;
    ListNode* prev = nullptr;
    int idx = 0;
    while(cur)
    {
        lists.push_back(cur);
        int i = 0;
        while(cur && i < k)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        prev->next = nullptr;
        if(i == k) idx++;
    }
    for(int i = 0; i < idx; ++i)
        lists[i] = reverseList(lists[i]);
    return connectAllList(lists, idx);
}       

int main() 
{
    fastio(true);
    int testCase;
    cin >> testCase;
    for(int test = 1; test <= testCase; ++test)
    {
        int cnt, k;     
        cin >> cnt >> k;
        ListNode* list = createListOfSize(cnt, k);
        list = reverseKGroup(list, k);
        cout << "TestCase #" << test << ": ";
        print(list);
    }
    return 0;
}