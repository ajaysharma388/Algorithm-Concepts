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


int main(){
    struct node* head = buildList();
    print(head);
    head = insertAfter(head,8);
    print(head);
    return 0;
}