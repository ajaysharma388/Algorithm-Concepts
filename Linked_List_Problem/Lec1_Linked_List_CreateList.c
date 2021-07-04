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



int main(){
    struct node* head = buildList();
    print(head);
    return 0;
}