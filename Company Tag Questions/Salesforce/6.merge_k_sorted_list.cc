/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define pin pair<int, ListNode*>
#define mp make_pair


class Compare {
public:
    bool operator()(pin a, pin b)
    {
        return a.first > b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int k = lists.size();
        priority_queue<pin, vector<pin>, Compare> pq;  
        for(int i = 0; i < k; ++i)
            if(lists[i]) pq.push(mp(lists[i]->val, lists[i]));

        while(!pq.empty())
        {
            pin cur = pq.top();
            pq.pop();
            if(head == nullptr)
            {
                head = cur.second;
                tail = cur.second;
            }
            else
            {
                tail->next = cur.second;
                tail = cur.second;
            }
            cur.second = cur.second->next;
            if(cur.second)
            {
                pq.push(mp(cur.second->val, cur.second));
            }
        }
        return head;
    }
};