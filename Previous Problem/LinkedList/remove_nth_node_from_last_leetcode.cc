#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class ListNode {
public:
	int val;
	ListNode*next;
	ListNode(const int data) {
		this->val = data;
		this->next = NULL;
	}
};

ListNode* createList() {
	int data;
	cin >> data;	
	if(data == -1) return NULL;
	ListNode*ptr = new ListNode(data);
	ptr->next = createList();
	return ptr;
}

void printList(ListNode *head) {
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	return;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode*pre = head;
    ListNode*first = head;
    ListNode*last = head;
    if(first->next == NULL and n == 1) {
    	delete head;
    	return NULL;
    }
    while(n-- > 1) {
        last = last->next;
    }
    while(last->next != NULL) {
    	pre = first;
    	first = first->next;
    	last = last->next;
    }
    if(pre == first) {
    	head = pre->next;
    	delete pre;
    	return head;
    }
    // Delete the node which is pointed by first.
    pre->next = first->next;
    first->next = NULL;
    delete first;
    return head;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ListNode*head = createList();
	int n;
	cin >> n;
	head = removeNthFromEnd(head,n);
	printList(head);
	return 0;
}