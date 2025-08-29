#include<stdio.h>
#include<stdlib.h>

// Structure that represents the node of the linked list.
struct node{
    int data;
    struct node* next; 
};

// This method recursive all the node into linked list 
// until it gets -1 as the input from the user.
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

int popFront(struct node**headRef) {
    struct node* head = *headRef;
    if(head == NULL) return -1;
    int data = head->data;
    *headRef = head->next;
    free(head);
    return data;
}

int main(){
    struct node* headRef = buildListIterative();
    printf("List => ");
    print(headRef);
    int result = popFront(&headRef);
    printf("Element At Front : %d\n", result);
    printf("List => ");
    print(headRef);
    return 0;
}

// Sample Input :

// 1 2 3 4 5 6 -1

// Sample Output :

// List => 1 2 3 4 5 6 
// Element At Front : 1
// List => 2 3 4 5 6
