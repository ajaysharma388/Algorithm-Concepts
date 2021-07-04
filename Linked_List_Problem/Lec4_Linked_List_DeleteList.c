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

void deleteList(struct node*headRef) {
    if(headRef == NULL) return;
    struct node*tmp = NULL;
    while(headRef != NULL) {
        tmp = headRef;
        headRef = headRef->next;
        print(tmp);
        free(tmp);
    }
    if(headRef == NULL) {
        printf("List is empty now..\n");
    } else {
        print(headRef);
    }
}

int main(){
    struct node* headRef = buildListIterative();
    int k;
    scanf("%d", &k);
    printf("List => ");
    print(headRef);
    printf("deleting the list nodes..\n");
    deleteList(headRef);
    return 0;
}

// Sample Input :

// 1 2 3 4 5 6 -1

// Sample Output :

// List => 1 2 3 4 5 6 
// deleting the list nodes..
// 1 2 3 4 5 6 
// 2 3 4 5 6 
// 3 4 5 6 
// 4 5 6 
// 5 6 
// 6 
// List is empty now..