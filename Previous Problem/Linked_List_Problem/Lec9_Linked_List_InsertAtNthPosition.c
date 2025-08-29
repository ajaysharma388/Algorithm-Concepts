#include<stdio.h>
#include<stdlib.h>

// Structure that represents the node of the linked list.
struct node{
    int data;
    struct node* next; 
};

// This method recursive all the node into linked list until it gets -1 as the input from the user.

struct node* buildList(){
    int data;
    scanf("%d",&data);
    if(data!=-1){
        struct node* root = (struct node*) malloc(sizeof (struct node));
        root->data = data;
        root->next = buildList();
        return root;
    }else{
        return NULL;
    }    
}


// The following subroutine will create the linked list 
// iteratively compare the two methods for more understanding.
struct node* buildListIterative() {
    struct node* headRef = NULL;
    struct node* tmp = NULL;
    int data;
    scanf("%d", &data);
    while(data != -1) {
        struct node* ptr = (struct node*) malloc(sizeof (struct node));
        ptr->data = data;
        if(headRef == NULL) {
            headRef = ptr;
            tmp = headRef;
        } else {
            tmp->next = ptr;
            tmp = tmp->next;
        }
        scanf("%d", &data);
    }
    tmp->next = NULL;
    return headRef;
}

// Prints the entire List.Time Complexity will be O(n).
// since, it traverse the entire list element one by one.
void print(struct node* root){
    while(root!=NULL){
        printf("%d ",root->data);
        root = root->next;
    }
    printf("\n");
}


// It takes root node & the data after which the user is trying to insert the data.
// If the data is not present after which the user is trying to add the value.
// This algorithm will simply add that new value at the end of the list.
// Time Complexity in worst case O(n).
struct node* insertAfter(struct node* root,int data){
    struct node* pre = root;
    struct node* post = root;
    while(pre->data!=data && post!=NULL){
        pre = post;
        post = post->next;
    }
    struct node* ptr = (struct node*) malloc(sizeof (struct node));
    scanf("%d",&ptr->data);
    ptr->next = post;
    pre->next = ptr;    
    return root;
}


int getLength(struct node* headRef) {
    int len = 0;
    while(headRef) {
        len += 1;
        headRef = headRef->next;
    }
    return len;
}

void insertAtNthIndex(struct node**headRef, int pos, int data) {
    int idx = 1;
    struct node* head = *headRef;
    while(head && idx < pos-1) {
        head = head->next;
        idx += 1;
    }    
    struct node* ptr = (struct node*) malloc(sizeof (struct node*));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}


int main(){
    struct node* head = buildListIterative();
    print(head);
    int len = getLength(head);
    int k, data;
    scanf("%d%d", &k, &data);
    if(k <= len) {
        // insert at nth position function.
        insertAtNthIndex(&head, k, data);
        print(head);
    } else {
        printf("Not Possible Since List length is %d", len);
    }
    return 0;
}

// Sample Input :

// 1 2 3 4 5 6 -1 
// 4 100

// Sample Output :

// 1 2 3 4 5 6 
// 1 2 3 100 4 5 6 