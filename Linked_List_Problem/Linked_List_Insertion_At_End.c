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

// This method takes the root as the input and add the element 
// at the end of the linked list.
// Time Complexity is of the order O(n).

struct node* insertAtEnd(struct node* root){
    int data;
    scanf("%d",&data);
    struct node* ptr = root;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = (struct node*) malloc(sizeof (struct node));
    ptr = ptr->next;
    ptr->data = data;
    ptr->next = NULL;
    return root;
}

int main(){
    struct node* head = buildList();
    print(head);
    head = insertAtEnd(head);
    print(head);
    return 0;
}